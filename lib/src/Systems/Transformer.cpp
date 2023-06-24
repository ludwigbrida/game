#include "Transformer.hpp"
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Parent.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/NewRegistry.hpp>

namespace Engine {

void Transformer::run(NewRegistry& registry, State& state, const Clock& clock) {
	auto entities = registry.view<Transform>();

	for (auto entity: entities) {
		auto& transform = registry.get<Transform>(entity);

		// TODO: temporarily scope to cube only
		if (entity == 2) {
			transform.rotation = Quaternion<Float>::fromAxisAngle(
				Vector3<Float>::Right,
				clock.elapsedTime * 100
			);
		}

		auto localTransform = Matrix4<Float>::fromTransform(transform);
		auto worldTransform = localTransform;

		if (registry.has<Parent>(entity)) {
			auto& parent = registry.get<Parent>(entity);

			if (registry.has<Matrices>(parent.entity)) {
				auto& parentMatrices = registry.get<Matrices>(parent.entity);

				worldTransform = localTransform * parentMatrices.world;
			}
		}

		if (registry.has<Matrices>(entity)) {
			auto& matrices = registry.get<Matrices>(entity);

			matrices.local = localTransform;
			matrices.world = worldTransform;
		} else {
			registry.add<Matrices>(
				entity,
				{.local = localTransform, .world = worldTransform}
			);
		}
	}
}

}
