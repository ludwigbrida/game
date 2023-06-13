#include <Engine/Components/Mass.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Systems/Gravity.hpp>

namespace ng {

void Gravity::update(Registry& registry, State& state, const Clock& clock) {
	auto entities = registry.view<Transform, Mass>();

	for (auto entity: entities) {
		const Mass& mass = registry.get<Mass>(entity);

		registry.update<Transform>(entity, [&](Transform& transform) {
			transform.position.y -= acceleration * mass.value * clock.deltaTime;
		});
	}
}

}
