#include "Game.hpp"
#include "../Systems/Movement.hpp"
#include "Engine/Components/Transform.hpp"

namespace Engine {

struct Transform2 {
	Vector3<Float> position;
};

}

Game::Game() {
	registry.activate<Movement>();

	Engine::Transform2 transform = {{0, 0, 0}};

	registry.add<Engine::Transform>(0);

	registry.remove<Engine::Transform>(0);

	registry.deactivate<Movement>();
}
