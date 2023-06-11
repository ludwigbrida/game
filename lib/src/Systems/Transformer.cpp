#include "Transformer.hpp"
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Parent.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>

namespace ng {

void Transformer::update(Registry& registry, State& state, const Clock& clock) {
	auto entities = registry.view<Transform>();

	for (auto entity: entities) {
		auto& transform = registry.get<Transform>(entity);

		// TODO: Split into two systems?
		// - Transform2Local
		// - Local2Global
		// To prevent unnecessary recalculation of hierarchical matrices within
		// a single frame?

		// TODO: temporarily scope to cube only
		if (entity == 2) {
			registry.update<Transform>(entity, [&](auto& currentTransform) {
				currentTransform.rotation = Quaternion<Float>::fromAxisAngle(
					Vector3<Float>::Right,
					clock.elapsedTime * 100
				);
			});
		}

		if (transform.isDirty) {
			registry.update<Matrices>(entity, [&](auto& matrices) {
				matrices.local = Matrix4<Float>::fromTransform(transform);
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
