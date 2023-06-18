#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

#include "../Graphics/Shader.hpp"
#include "../Graphics/VertexArray.hpp"
#include <Engine/Components/Mesh.hpp>
#include <Engine/Core/Entity.hpp>
#include <Engine/Core/System.hpp>
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Matrix4.hpp>
#include <memory>
#include <unordered_map>

namespace ng {

class Renderer: public System {
public:
	void setup() override;
	void update(Registry& registry, State& state, const Clock& clock) override;

private:
	void clear(const Color& color) const;
	void draw(
		const VertexArray& vertexArray,
		const Shader& shader,
		const Matrix4<Float>& modelMatrix
	) const;

	// TODO
	Matrix4<Float> viewMatrix{Matrix4<Float>::Identity};
	Matrix4<Float> projectionMatrix{Matrix4<Float>::Identity};

	std::unordered_map<Entity, std::unique_ptr<VertexArray>> targets;
};

}

#endif
