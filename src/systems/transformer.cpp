#include "transformer.hpp"
#include "../components/transform.hpp"
#include "../ecs/registry.hpp" // TODO: Extract
#include <iostream>

void Transformer::update(struct Registry& registry, float deltaTime) const {
	auto entities = registry.view<Transform>();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);

		transform.position.x = 5;
	}
}