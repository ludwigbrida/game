#include "renderer.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp"
#include "../models/color.hpp"
#include <GLFW/glfw3.h>

void Renderer::run(Registry& registry, float deltaTime) const {
	auto entities = registry.view<Transform, Mesh>();

	clear(Color::black);

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
		auto& mesh = registry.get<Mesh>(entity);

		draw();
	}
}

void Renderer::clear(const Color& color) const {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw() const {}
