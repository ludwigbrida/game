#include "RenderSystem.hpp"
#include "../../components/mesh.hpp"
#include "../../components/transform.hpp"
#include "../../ecs/Registry/Registry.hpp"

void RenderSystem::run(Registry& registry, float deltaTime) {
	auto entities = registry.view<Transform, Mesh>();

	for (auto entity : entities) {
		auto& transform = registry.getComponent<Transform>(entity);
		auto& mesh = registry.getComponent<Mesh>(entity);
	}
}
