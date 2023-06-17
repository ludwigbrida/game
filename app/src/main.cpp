#include "Systems/Movement.hpp"
#include <Engine/Components/Collider.hpp>
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Mesh.hpp>
#include <Engine/Components/Physics.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/App.hpp>
#include <Engine/Systems/Gravity.hpp>

using namespace ng;

int main() {
	ng::App app;

	app.registry.activate<Movement>();
	app.registry.activate<ng::Gravity>({9.81});

	auto player = 0;
	app.registry.add<ng::Transform>(player);
	app.registry.add<ng::Matrices>(player);
	app.registry.add<ng::Perspective>(
		player,
		{.fieldOfView = 45_deg, .aspectRatio = 16. / 9, .near = .1, .far = 1000}
	);
	app.registry.add<ng::Collider>(
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
	app.registry.add<ng::Transform>(triangle, {.position{-1, 0, -2}});
	app.registry.add<ng::Matrices>(triangle);
	app.registry.add<ng::Mesh>(triangle, ng::Mesh::createTriangle(1));
	app.registry.add<ng::Physics>(triangle);

	auto cube = 2;
	app.registry.add<ng::Transform>(cube, {.position{1, 0, -2}});
	app.registry.add<ng::Matrices>(cube);
	app.registry.add<ng::Mesh>(cube, ng::Mesh::createCube(1));
	app.registry.add<ng::Collider>(
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

	app.state.activeCamera = player;

	app.run();
}
