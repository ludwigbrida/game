#include "Game.hpp"
#include "../../../lib/src/Systems/Collision.hpp"
#include "../../../lib/src/Systems/Renderer.hpp"
#include "../Systems/Movement.hpp"
#include <Engine/Components/Mesh.hpp>
#include <Engine/Components/Perspective.hpp>
#include <Engine/Components/Physics.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Systems/Gravity.hpp>

Game::Game() {
	constexpr auto player = 0;
	registry.add<Engine::Transform>(player, Engine::Transform());
	registry.add<Engine::Perspective>(player, Engine::Perspective());

	constexpr auto triangle = 1;
	registry.add<Engine::Transform>(triangle, {.position = {-1, 0, -2}});
	registry.add<Engine::Mesh>(triangle, Engine::Mesh::createTriangle(1));
	registry.add<Engine::Physics>(triangle, Engine::Physics());

	state.activeCamera = player;

	registry.activate<Engine::Gravity>(9.81);
	registry.activate<Movement>();
	// registry.activate<Engine::Collision>(); // remove Matrices component
	registry.activate<Engine::Renderer>();
}
