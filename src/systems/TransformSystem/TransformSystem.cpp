#include "TransformSystem.hpp"
#include "../../components/TransformComponent.hpp"

// TODO: Extract
#include "../../ecs/Registry/Registry.hpp"

void TransformSystem::run(Registry& registry, float deltaTime) {
	auto entities = registry.view<TransformComponent>();

	for (auto entity : entities) {
		ComponentType auto& transform =
				registry.getComponent<TransformComponent>(entity);

		transform.position.x = 5;
	}
}
