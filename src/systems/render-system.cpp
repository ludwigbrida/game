#include "render-system.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp"
#include <GLFW/glfw3.h>

void RenderSystem::run(Registry& registry, float deltaTime) {
	auto entities = registry.view<Transform, Mesh>();

	clear();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
		auto& mesh = registry.get<Mesh>(entity);

		draw();
	}
}

void RenderSystem::clear() const {
	glClearColor(0.25, 0.25, 0.75, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void RenderSystem::draw() const {}
