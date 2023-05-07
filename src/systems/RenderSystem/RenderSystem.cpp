#include "RenderSystem.hpp"
#include "../../components/MeshComponent.hpp"
#include "../../components/TransformComponent.hpp"
#include "../../ecs/Registry/Registry.hpp"

void RenderSystem::run(Registry& registry, float deltaTime) {
	auto entities = registry.view<TransformComponent, MeshComponent>();

	for (auto entity : entities) {
		auto& transform = registry.getComponent<TransformComponent>(entity);
		auto& mesh = registry.getComponent<MeshComponent>(entity);
	}
}
