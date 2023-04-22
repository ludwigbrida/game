#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "../ecs/Registry/Registry.hpp"

class System {
	virtual void run(const Registry& registry) = 0;
};

#endif
