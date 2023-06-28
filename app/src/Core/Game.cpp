#include "Game.hpp"
#include "../../../lib/src/Systems/Collision.hpp"
#include "../../../lib/src/Systems/Renderer.hpp"
#include "../Components/Spin.hpp"
#include "../Systems/Movement.hpp"
#include "../Systems/Rotation.hpp"
#include <Engine/Components/Mesh.hpp>
#include <Engine/Components/Perspective.hpp>
#include <Engine/Components/Physics.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Systems/Gravity.hpp>

Game::Game() {
	constexpr auto player = 0;
	registry.add<Engine::Transform>(player, Engine::Transform());
	registry.add<Engine::Perspective>(player, Engine::Perspective());
	registry.add<Engine::Collider>(
		player,
		{.vertices{
			{-.5, .5, -.5},
			{.5, .5, -.5},
			{-.5, .5, .5},
			{.5, .5, .5},
			{-.5, -.5, -.5},
			{.5, -.5, -.5},
			{-.5, -.5, .5},
			{.5, -.5, .5},
		}}
	);

	constexpr auto triangle = 1;
	registry.add<Engine::Transform>(triangle, {.position = {-1, 0, -2}});
	registry.add<Engine::Mesh>(triangle, Engine::Mesh::createTriangle(1, 0));
	registry.add<Engine::Physics>(triangle, Engine::Physics());

	constexpr auto cube = 2;
	registry.add<Engine::Transform>(cube, {.position{1, 0, -2}});
	registry.add<Engine::Mesh>(cube, Engine::Mesh::createCube(1, 1));
	registry.add<Engine::Collider>(
		cube,
		{.vertices{
			{-.5, .5, -.5},
			{.5, .5, -.5},
			{-.5, .5, .5},
			{.5, .5, .5},
			{-.5, -.5, -.5},
			{.5, -.5, -.5},
			{-.5, -.5, .5},
			{.5, -.5, .5},
		}}
	);
	registry.add<Spin>(
		cube,
		{.axis = Engine::Vector3<Engine::Float>::Up, .speed = 100.f}
	);

	state.activeCamera = player;

	registry.activate<Movement>();
	registry.activate<Rotation>();
	// registry.activate<Engine::Gravity>(9.81);
	registry.activate<Engine::Collision>();
	registry.activate<Engine::Renderer>();
}
