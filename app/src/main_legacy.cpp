/*
#include "Systems/Movement.hpp"
#include <Engine/Components/Collider.hpp>
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Mesh.hpp>
#include <Engine/Components/Physics.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/App.hpp>
#include <Engine/Systems/Gravity.hpp>

using namespace Engine;

int main_legacy() {
	Engine::App app;

	app.registry.activate<Movement>();
	app.registry.activate<Engine::Gravity>({9.81});

	auto player = 0;
	app.registry.add<Engine::Transform>(player);
	app.registry.add<Engine::Matrices>(player);
	app.registry.add<Engine::Perspective>(
		player,
		{.fieldOfView = 45_deg, .aspectRatio = 16. / 9, .near = .1, .far = 1000}
	);
	app.registry.add<Engine::Collider>(
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

	auto triangle = 1;
	app.registry.add<Engine::Transform>(triangle, {.position{-1, 0, -2}});
	app.registry.add<Engine::Matrices>(triangle);
	app.registry.add<Engine::Mesh>(triangle, Engine::Mesh::createTriangle(1));
	app.registry.add<Engine::Physics>(triangle);

	auto cube = 2;
	app.registry.add<Engine::Transform>(cube, {.position{1, 0, -2}});
	app.registry.add<Engine::Matrices>(cube);
	app.registry.add<Engine::Mesh>(cube, Engine::Mesh::createCube(1));
	app.registry.add<Engine::Collider>(
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

	auto skybox = 3;
	app.registry.add<Engine::Transform>(skybox);
	app.registry.add<Engine::Matrices>(skybox);

	app.state.activeCamera = player;

	app.run();
}
*/
