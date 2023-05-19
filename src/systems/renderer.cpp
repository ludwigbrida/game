#include "renderer.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp"
#include "../graphics/color.hpp"
#include "../maths/radian.hpp"
#include <iostream>

void Renderer::setup() {
	auto vertexShader = createShader(GL_VERTEX_SHADER, R"(
#version 410 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout (location = 0) in vec3 vertexPosition;

void main() {
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1);
}
)");

	auto fragmentShader = createShader(GL_FRAGMENT_SHADER, R"(
#version 410 core

out vec4 color;

void main() {
	color = vec4(1, .5, .2, 1);
}
)");

	program = createProgram(vertexShader, fragmentShader);

	modelMatrixLocation = glGetUniformLocation(program, "modelMatrix");
	viewMatrixLocation = glGetUniformLocation(program, "viewMatrix");
	projectionMatrixLocation = glGetUniformLocation(program, "projectionMatrix");

	/*
	float vertices[] = {
		0.5f,	 0.5f,	0.0f, // top right
		0.5f,	 -0.5f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f, 0.5f,	0.0f	// top left
	};

	unsigned int indices[] = {
		// note that we start from 0!
		0, 1, 3, // first triangle
		1, 2, 3	 // second triangle
	};

	vertexArray = createVertexArray();
	glBindVertexArray(vertexArray);

	auto vertexBuffer = createBuffer();
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
												(void*)nullptr);
	glEnableVertexAttribArray(0);

	auto indexBuffer = createBuffer();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
							 GL_STATIC_DRAW);
							 */

	add(1, Mesh::createTriangle(1));
}

void Renderer::update(struct Registry& registry, float deltaTime) const {
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
		// vertices.push_back(vertex.normal.x);
		// vertices.push_back(vertex.normal.y);
		// vertices.push_back(vertex.normal.z);
		// vertices.push_back(vertex.color.x);
		// vertices.push_back(vertex.color.y);
		// vertices.push_back(vertex.color.z);
	}

	auto vertexBuffer = createBuffer();
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
							 vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
												(void*)nullptr);
	glEnableVertexAttribArray(0);

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
