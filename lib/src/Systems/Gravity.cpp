#include <Engine/Components/Physics.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Systems/Gravity.hpp>

namespace Engine {

void Gravity::run(Registry& registry, State& state, const Clock& clock) {
	auto entities = registry.view<Transform, Physics>();

	for (auto entity: entities) {
		auto& physics = registry.get<Physics>(entity);

		physics.acceleration += constant * physics.mass * clock.deltaTime;
		physics.velocity += physics.acceleration * clock.deltaTime;

		registry.update<Transform>(entity, [&](Transform& transform) {
			transform.position += physics.velocity * clock.deltaTime;
		});
	}
}

}
