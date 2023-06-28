#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

#include "../Graphics/Material.hpp"
#include "../Graphics/Shader.hpp"
#include "../Graphics/Texture.hpp"
#include "../Graphics/TextureCube.hpp"
#include "../Graphics/VertexArray.hpp"
#include "../Graphics/VertexArrayCube.hpp"
#include <Engine/Components/Mesh.hpp>
#include <Engine/Core/Entity.hpp>
#include <Engine/Core/System.hpp>
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Matrix4.hpp>
#include <memory>
#include <unordered_map>

namespace Engine {

class Renderer: public System {
public:
	Renderer();

	void run(Registry& registry, State& state, const Clock& clock) override;

private:
	void clear(const Color& color) const;

	void draw(
		const VertexArray& vertexArray,
		const Material& material,
		const Matrix4<Float>& modelMatrix
	) const;

	void drawSkybox() const;

	// TODO
	Matrix4<Float> viewMatrix{Matrix4<Float>::Identity};
	Matrix4<Float> projectionMatrix{Matrix4<Float>::Identity};

	std::unordered_map<Entity, std::unique_ptr<VertexArray>> targets;
	std::unordered_map<UInt32, std::unique_ptr<Material>> materials;

	std::unique_ptr<VertexArrayCube> skyboxVertexArray;
	std::unique_ptr<Shader> skyboxShader;
	std::unique_ptr<TextureCube> skyboxTexture;
};

}

#endif
