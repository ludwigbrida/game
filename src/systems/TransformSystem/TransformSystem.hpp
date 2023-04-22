#ifndef GAME_TRANSFORM_SYSTEM_HPP
#define GAME_TRANSFORM_SYSTEM_HPP

#include "../System.hpp"

class TransformSystem : System {
public:
	void run(const Registry& registry) final;
};

#endif
