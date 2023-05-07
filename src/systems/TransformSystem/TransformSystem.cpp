#include "TransformSystem.hpp"
#include "../../components/TransformComponent.hpp"
#include "../../ecs/Registry/Registry.hpp" // TODO: Extract
#include <iostream>

void TransformSystem::run(Registry& registry, float deltaTime) {
	auto entities = registry.view<TransformComponent>();

	for (auto entity : entities) {
		ComponentType auto& transform =
				registry.getComponent<TransformComponent>(entity);

		std::cout << "Entity: " << entity << std::endl;

		transform.position.x = 5;
	}
}
