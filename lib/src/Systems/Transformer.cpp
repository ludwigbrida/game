#include "Transformer.hpp"
#include "Components/TransformMatrix.hpp"
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>
#include <iostream>

namespace ng {

void Transformer::update(Registry& registry, State& state, Float deltaTime) {
	auto entities = registry.view<Transform>();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);

		if (registry.has<TransformMatrix>(entity)) {
			auto& test = registry.get<TransformMatrix>(entity);

			std::cout << test.local << std::endl << std::endl;
		}

		// TODO: Split into two systems?
		// - Transform2Local
		// - Local2Global
		// To prevent unnecessary recalculation of hierarchical matrices within
		// a single frame?
		if (transform.isDirty) {

			transform.position.x = 5;

			registry.update<TransformMatrix>(
				entity, [&transform](auto& transformMatrix) {
					transformMatrix.local = Matrix4f::fromTransform(transform);
				});

			transform.isDirty = false;
		}
	}
}

}
