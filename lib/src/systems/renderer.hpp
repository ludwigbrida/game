#ifndef GAME_RENDERER_HPP
#define GAME_RENDERER_HPP

#include "../components/Transform.hpp"
#include "../core/State.hpp"
#include "../ecs/entity.hpp"
#include "../ecs/system.hpp"
#include "../math/matrix.hpp"
#include "../types_legacy/primitive.hpp"
#include <Engine/Graphics/Color.hpp>
#include <GL/glew.h>
#include <memory>
#include <unordered_map>

class Renderer : public System {
public:
	void setup() final;
	void update(class Registry& registry, struct State& state,
							float deltaTime) final;

private:
	void clear(const ng::Color& color) const;
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
