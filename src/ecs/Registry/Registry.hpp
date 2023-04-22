#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../systems/System.hpp"
#include <memory>
#include <vector>

class Registry {
public:
	void addSystem(const std::shared_ptr<System>& system);

private:
	std::vector<std::shared_ptr<System>> systems;
};

#endif
