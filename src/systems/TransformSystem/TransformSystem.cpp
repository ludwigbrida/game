#include "TransformSystem.hpp"
#include "../../components/TransformComponent.hpp"

// TODO: Extract
#include "../../ecs/Registry/Registry.hpp"

void TransformSystem::run(Registry& registry, float deltaTime) {
	auto entities = registry.view<TransformComponent>();
	for (auto& entity : entities) {
		auto transformComponent = registry.getComponent<TransformComponent>(entity);
		transformComponent.position.x = 5;
	}
}
