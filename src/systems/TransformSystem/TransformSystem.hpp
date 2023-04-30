#ifndef GAME_TRANSFORM_SYSTEM_HPP
#define GAME_TRANSFORM_SYSTEM_HPP

#include "../System.hpp"

class TransformSystem : public System<TransformComponent> {
public:
	void run(const float& deltaTime) final;
};

#endif
