#include "Game.hpp"
#include "../Systems/Movement.hpp"

Game::Game() {
	registry.activate<Movement>();
	registry.deactivate<Movement>();
}
