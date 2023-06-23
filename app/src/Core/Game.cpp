#include "Game.hpp"
#include <Engine/Components/Transform.hpp>

Game::Game(): ng::Application{"Game"} {
	const auto triangle = 1;
	registry.add<ng::Transform>(triangle);
}
