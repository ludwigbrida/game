#include "transformer.hpp"
#include "../core/State.hpp"
#include "../ecs/registry.hpp" // TODO: Extract
#include <Engine/Components/Transform.hpp>
#include <iostream>

void Transformer::update(Registry& registry, State& state, float deltaTime) {
	auto entities = registry.view<ng::Transform>();

	for (auto entity : entities) {
		auto& transform = registry.get<ng::Transform>(entity);
	}
}
