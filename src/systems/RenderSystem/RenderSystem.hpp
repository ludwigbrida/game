#ifndef GAME_RENDER_SYSTEM_HPP
#define GAME_RENDER_SYSTEM_HPP

#include "../../ecs/System.hpp"

class RenderSystem : public System {
public:
	void run(Registry& registry, float deltaTime) final;
};

#endif
