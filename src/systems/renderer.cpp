#include "renderer.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp"
#include "../graphics/color.hpp"

void Renderer::setup() {
	auto vertexShader = createShader(GL_VERTEX_SHADER, "");
	auto fragmentShader = createShader(GL_FRAGMENT_SHADER, "");
	auto program = createProgram(vertexShader, fragmentShader);
}

void Renderer::update(struct Registry& registry, float deltaTime) const {
	auto entities = registry.view<Transform, Mesh>();

	clear(Color::black);

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
	// const float[] vertices = mesh.vertices;
}

UInt Renderer::createShader(GLenum type, const char* source) {
	auto shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);
	return shader;
}

UInt Renderer::createProgram(UInt vertexShader, UInt fragmentShader) {
	auto program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	return program;
}
