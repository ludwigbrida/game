#include "Game.hpp"
#include "../Systems/Movement.hpp"
#include "Engine/Components/Transform.hpp"

namespace Engine {

struct Component2 {};

struct Transform2: Component2 {
	Vector3<Float> position;
	Quaternion<Float> rotation;
	Vector3<Float> scale;
};

struct Position: Vector3<Float>, Component2 {
	using Vector3<Float>::Vector3;
};

}

Game::Game() {
	registry.activate<Movement>();

	Engine::Transform2 transform = {
		.position = {0, 0, 0},
		.rotation = {0, 0, 0, 1},
		.scale = {1, 1, 1}};

	std::unique_ptr<Engine::Component2> com =
		std::make_unique<Engine::Position>(0, 0, 0);

	registry.add<Engine::Transform>(0, transform);

	registry.remove<Engine::Transform>(0);

	registry.deactivate<Movement>();
}
