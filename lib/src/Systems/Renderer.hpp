#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

#include "../Graphics/Program.hpp"
#include "../Graphics/VertexArray.hpp"
#include <Engine/Components/Mesh.hpp>
#include <Engine/Core/Entity.hpp>
#include <Engine/Core/System.hpp>
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Matrix4.hpp>
#include <memory>
#include <unordered_map>

namespace ng {

class Renderer : public System {
public:
	void setup() override;
	void update(Registry& registry, State& state, Float deltaTime) override;

private:
	void clear(const Color& color) const;
	void draw(const VertexArray& vertexArray, const Program& program,
						const Matrix4f& modelMatrix) const;

	// TODO
	Matrix4f viewMatrix{Matrix4f::Identity};
	Matrix4f projectionMatrix{Matrix4f::Identity};

	std::unordered_map<Entity, std::unique_ptr<VertexArray>> targets;
};

}

#endif
