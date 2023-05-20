#include "transformer.hpp"
#include "../components/transform.hpp"
#include "../core/State.hpp"
#include "../ecs/registry.hpp" // TODO: Extract
#include <iostream>

void Transformer::update(Registry& registry, State& state, float deltaTime) {
	auto entities = registry.view<Transform>();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
	}
}
