#ifndef GAME_TRANSFORMER_HPP
#define GAME_TRANSFORMER_HPP

#include "../ecs/system.hpp"

class Transformer : public System {
public:
	void update(class Registry& registry, struct State& state,
							float deltaTime) final;
};

#endif
