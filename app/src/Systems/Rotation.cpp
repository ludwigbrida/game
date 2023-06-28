#include "Rotation.hpp"
#include "../Components/Spin.hpp"
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>

void Rotation::run(
	Engine::Registry& registry,
	Engine::State& state,
	const Engine::Clock& clock
) {
	auto entities = registry.view<Engine::Transform, Spin>();

	for (auto entity: entities) {
		auto& transform = registry.get<Engine::Transform>(entity);
		const auto& spin = registry.get<Spin>(entity);

		transform.rotation = Engine::Quaternion<Engine::Float>::fromAxisAngle(
			spin.axis,
			spin.speed * clock.elapsedTime
		);
	}
}
