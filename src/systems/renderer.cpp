#include "renderer.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp"
#include "../graphics/color.hpp"
#include <iostream>

void Renderer::setup() {
	auto vertexShader = createShader(GL_VERTEX_SHADER, R"(
#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
)");
	auto fragmentShader = createShader(GL_FRAGMENT_SHADER, R"(
#version 330 core
out vec4 FragColor;

void main()
{
		FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
)");
	program = createProgram(vertexShader, fragmentShader);
}

void Renderer::update(struct Registry& registry, float deltaTime) const {
	auto entities = registry.view<Transform, Mesh>();

	clear(Color::black);

	glUseProgram(program);

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
		auto& mesh = registry.get<Mesh>(entity);

		auto modelMatrix = Matrix4f::fromTransform(transform);

		draw(modelMatrix, mesh);
	}
}

void Renderer::clear(const Color& color) const {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Matrix4f& modelMatrix, const Mesh& mesh) const {
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
												(void*)nullptr);
	glEnableVertexAttribArray(0);

	// const float[] vertices = mesh.vertices;
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
