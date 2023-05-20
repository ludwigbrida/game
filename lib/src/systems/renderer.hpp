#ifndef GAME_RENDERER_HPP
#define GAME_RENDERER_HPP

#include "../components/transform.hpp"
#include "../core/State.hpp"
#include "../ecs/entity.hpp"
#include "../ecs/system.hpp"
#include "../maths/matrix.hpp"
#include "../types/primitive.hpp"
#include <GL/glew.h>
#include <memory>
#include <unordered_map>

class Renderer : public System {
public:
	void setup() final;
	void update(class Registry& registry, struct State& state,
							float deltaTime) final;

private:
	void clear(const class Color& color) const;
	void draw(const Matrix4f& modelMatrix, const Matrix4f& viewMatrix,
						const Matrix4f& projectionMatrix, const class Mesh& mesh) const;

	UInt createShader(GLenum type, const char* source);
	UInt createProgram(UInt vertexShader, UInt fragmentShader);
	UInt createBuffer();
	UInt createVertexArray();

	UInt program;

	Int modelMatrixLocation;
	Int viewMatrixLocation;
	Int projectionMatrixLocation;

	// New approach
	std::unordered_map<Entity, std::pair<UInt, Int>> vertexArrays;

	void add(Entity entity, const Mesh& mesh);
	void remove(Entity entity);
};

#endif
