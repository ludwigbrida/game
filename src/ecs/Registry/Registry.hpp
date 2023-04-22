#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../systems/System.hpp"
#include "../Entity.hpp"
#include <memory>
#include <vector>

class Registry {
public:
	void run(const float& deltaTime);

	void addSystem(const std::shared_ptr<System>& system);

private:
	std::vector<std::shared_ptr<Entity>> entities;
	std::vector<std::shared_ptr<System>> systems;
};

#endif
