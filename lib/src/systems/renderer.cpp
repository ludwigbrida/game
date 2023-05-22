#include "renderer.hpp"
#include "../components/Mesh.hpp"
#include "../components/Transform.hpp"
#include "../ecs/registry.hpp"
#include "../gfx/Color.hpp"
#include "../math/radian.hpp"
#include <iostream>

void Renderer::setup() {
	auto vertexShader = createShader(GL_VERTEX_SHADER, R"(
#version 410 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout (location = 0) in vec3 vertexPosition;
layout (location = 2) in vec3 vertexColor;

out vec3 fragmentColor;

void main() {
	fragmentColor = vertexColor;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1);
}
)");

	auto fragmentShader = createShader(GL_FRAGMENT_SHADER, R"(
#version 410 core

in vec3 fragmentColor;

out vec4 color;

void main() {
	color = vec4(fragmentColor, 1);
}
)");

	program = createProgram(vertexShader, fragmentShader);

	modelMatrixLocation = glGetUniformLocation(program, "modelMatrix");
	viewMatrixLocation = glGetUniformLocation(program, "viewMatrix");
	projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix");
}

void Renderer::update(Registry& registry, State& state, float deltaTime) {
	auto entities = registry.view<Transform, Mesh>();

	clear(Color::black);

	glUseProgram(program);

	auto projectionMatrix =
		Matrix4f::fromPerspective(fromDegrees(90), 16. / 9, .1, 1000);

	auto cameraTranslation = Matrix4f::fromTranslation({0, 0, 0});
	auto cameraRotation = Matrix4f::fromRotation({0, 0, 0, 1});
	auto cameraMatrix = cameraRotation * cameraTranslation;

	auto viewMatrix = cameraMatrix.inverted();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
		auto& mesh = registry.get<Mesh>(entity);

		if (!vertexArrays.contains(entity))
			add(entity, mesh);

		auto modelMatrix = Matrix4f::fromTransform(transform);

		draw(modelMatrix, viewMatrix, projectionMatrix, mesh);
	}
}

void Renderer::clear(const Color& color) const {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Matrix4f& modelMatrix, const Matrix4f& viewMatrix,
										const Matrix4f& projectionMatrix, const Mesh& mesh) const {
	glUniformMatrix4fv(modelMatrixLocation, 1, false, modelMatrix);
	glUniformMatrix4fv(viewMatrixLocation, 1, false, viewMatrix);
	glUniformMatrix4fv(projectionMatrixLocation, 1, false, projectionMatrix);

	for (auto [_, vertexArrayAndIndices] : vertexArrays) {
		auto [vertexArray, indices] = vertexArrayAndIndices;
		glBindVertexArray(vertexArray);

		glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);

		glBindVertexArray(0);
	}
}

UInt Renderer::createShader(GLenum type, const char* source) {
	auto shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	Int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cerr << infoLog << std::endl;
	}

	return shader;
}

UInt Renderer::createProgram(UInt vertexShader, UInt fragmentShader) {
	auto program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	Int success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		std::cerr << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return program;
}

UInt Renderer::createBuffer() {
	UInt buffer;
	glGenBuffers(1, &buffer);
	return buffer;
}

UInt Renderer::createVertexArray() {
	UInt vertexArray;
	glGenVertexArrays(1, &vertexArray);
	return vertexArray;
}

// New approach

void Renderer::add(Entity entity, const Mesh& mesh) {
	auto vertexArray = createVertexArray();
	glBindVertexArray(vertexArray);

	std::vector<float> vertices;
	for (const auto& vertex : mesh.vertices) {
		vertices.push_back(vertex.position.x);
		vertices.push_back(vertex.position.y);
		vertices.push_back(vertex.position.z);
		vertices.push_back(vertex.normal.x);
		vertices.push_back(vertex.normal.y);
		vertices.push_back(vertex.normal.z);
		vertices.push_back(vertex.color.r);
		vertices.push_back(vertex.color.g);
		vertices.push_back(vertex.color.b);
	}

	auto vertexBuffer = createBuffer();
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
							 vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float),
												(void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float),
												(void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	auto indexBuffer = createBuffer();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
							 mesh.indices.size() * sizeof(unsigned int), mesh.indices.data(),
							 GL_STATIC_DRAW);

	glBindVertexArray(0);

	vertexArrays.insert({entity, {vertexArray, mesh.indices.size()}});
}

void Renderer::remove(Entity entity) {
	auto [vertexArray, _] = vertexArrays.at(entity);

	glDeleteVertexArrays(1, &vertexArray);

	vertexArrays.erase(entity);
}
