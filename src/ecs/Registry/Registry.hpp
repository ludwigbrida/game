#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../systems/System.hpp"
#include <memory>
#include <vector>

class Registry {
private:
	std::vector<std::shared_ptr<System>> systems;
};

#endif
