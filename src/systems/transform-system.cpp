#include "transform-system.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp" // TODO: Extract
#include <iostream>

void TransformSystem::run(Registry& registry, float deltaTime) {
	auto entities = registry.view<Transform>();

	for (auto entity : entities) {
		auto& transform = registry.getComponent<Transform>(entity);

		std::cout << "Entity: " << entity << std::endl;

		transform.position.x = 5;
	}
}
