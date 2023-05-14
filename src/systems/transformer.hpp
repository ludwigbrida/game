#ifndef GAME_TRANSFORMER_HPP
#define GAME_TRANSFORMER_HPP

#include "../ecs/system.hpp"

class Transformer : public System {
public:
	void update(struct Registry& registry, float deltaTime) const final;
};

#endif
