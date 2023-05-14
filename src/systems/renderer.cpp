#include "renderer.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp"
#include "../graphics/color.hpp"
#include <GLFW/glfw3.h>

void Renderer::setup() {
	// todo
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

void Renderer::createShader() {}
