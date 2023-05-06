#ifndef GAME_TRANSFORM_SYSTEM_HPP
#define GAME_TRANSFORM_SYSTEM_HPP

#include "../System.hpp"

class TransformSystem : public System {
public:
	void run(Registry& registry, float deltaTime) final;
};

#endif
