#ifndef GAME_RENDERER_HPP
#define GAME_RENDERER_HPP

#include "../components/transform.hpp"
#include "../ecs/system.hpp"
#include "../maths/matrix.hpp"
#include "../types/primitive.hpp"
#include <GL/glew.h>

class Renderer : public System {
public:
	void setup() final;
	void update(struct Registry& registry, float deltaTime) const final;

private:
	void clear(const class Color& color) const;
	void draw(const Matrix4f& transform, const class Mesh& mesh) const;

	UInt createShader(GLenum type, const char* source);
	UInt createProgram(UInt vertexShader, UInt fragmentShader);
	UInt createBuffer();
	UInt createVertexArray();

	UInt program;
	UInt vertexArray;
};

#endif
