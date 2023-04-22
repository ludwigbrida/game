#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "../ecs/Registry/Registry.hpp"

class System {
public:
	virtual void run(const Registry& registry, const float& deltaTime) = 0;
};

#endif
