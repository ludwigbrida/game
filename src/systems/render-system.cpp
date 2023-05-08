#include "render-system.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp"

void RenderSystem::run(Registry& registry, float deltaTime) {
	auto entities = registry.view<Transform, Mesh>();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
		auto& mesh = registry.get<Mesh>(entity);
	}
}
