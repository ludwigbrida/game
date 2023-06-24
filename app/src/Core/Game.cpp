#include "Game.hpp"
#include "../Systems/Movement.hpp"
#include <Engine/Components/Transform.hpp>

Game::Game() {
	registry.activate<Movement>();

	Engine::Transform transform = {
		.position = {0, 0, 0},
		.rotation = {0, 0, 0, 1},
		.scale = {1, 1, 1}};

	registry.add<Engine::Transform>(0, transform);

	auto& transform2 = registry.get<Engine::Transform>(0);

	registry.remove<Engine::Transform>(0);

	registry.deactivate<Movement>();
}
