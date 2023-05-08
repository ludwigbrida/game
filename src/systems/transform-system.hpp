#ifndef GAME_TRANSFORM_SYSTEM_HPP
#define GAME_TRANSFORM_SYSTEM_HPP

#include "../ecs/system.hpp"

class TransformSystem : public System {
public:
	void run(Registry& registry, float deltaTime) final;
};

#endif
