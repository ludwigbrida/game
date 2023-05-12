#ifndef GAME_RENDER_SYSTEM_HPP
#define GAME_RENDER_SYSTEM_HPP

#include "../ecs/system.hpp"

class RenderSystem : public System {
public:
	void run(Registry& registry, float deltaTime) const final;

private:
	void clear(const class Color& color) const;
	void draw() const;
};

#endif
