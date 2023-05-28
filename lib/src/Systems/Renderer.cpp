#include "Renderer.hpp"
#include "../Core/Registry.hpp"
#include <Engine/Components/Transform.hpp>

namespace ng {

void Renderer::update(Registry& registry, State& state, float deltaTime) {
	auto entities = registry.view<Transform>();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
	}
}

}
