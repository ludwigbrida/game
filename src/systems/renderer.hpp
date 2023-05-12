#ifndef GAME_RENDERER_HPP
#define GAME_RENDERER_HPP

#include "../ecs/system.hpp"

class Renderer : public System {
public:
	void run(Registry& registry, float deltaTime) const final;

private:
	void clear(const class Color& color) const;
	void draw() const;
};

#endif
