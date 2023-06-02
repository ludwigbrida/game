#include "Transformer.hpp"
#include "Engine/Components/Matrices.hpp"
#include <Engine/Components/Parent.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>

namespace ng {

void Transformer::update(Registry& registry, State& state, Float deltaTime) {
	auto entities = registry.view<Transform>();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);

		// TODO: Split into two systems?
		// - Transform2Local
		// - Local2Global
		// To prevent unnecessary recalculation of hierarchical matrices within
		// a single frame?

		if (transform.isDirty) {
			registry.update<Matrices>(entity, [&](auto& matrices) {
				matrices.local = Matrix4f::fromTransform(transform);
				matrices.world = matrices.local;

				if (registry.has<Parent>(entity)) {
					auto parent = registry.get<Parent>(entity);

					if (registry.has<Matrices>(parent.entity)) {
						auto parentMatrices = registry.get<Matrices>(parent.entity);

						matrices.world = matrices.local * parentMatrices.world;
					}
				}
			});
		}
	}
}

}
