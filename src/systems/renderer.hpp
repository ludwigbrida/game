#ifndef GAME_RENDERER_HPP
#define GAME_RENDERER_HPP

#include "../components/transform.hpp"
#include "../ecs/system.hpp"
#include "../maths/matrix.hpp"

class Renderer : public System {
public:
	void setup() final;
	void update(struct Registry& registry, float deltaTime) const final;

private:
	void clear(const class Color& color) const;
	void draw(const Matrix4f& transform, const class Mesh& mesh) const;

	void createShader();
};

#endif
