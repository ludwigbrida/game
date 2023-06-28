#ifndef ENGINE_MATERIAL_HPP
#define ENGINE_MATERIAL_HPP

#include "Shader.hpp"
#include "Texture.hpp"
#include <memory>

namespace Engine {

class Material {
public:
	explicit Material(
		const std::string& shaderPath,
		const std::string& diffusePath
	);

private:
	std::unique_ptr<Shader> shader;
	std::unique_ptr<Texture> diffuse;

	friend class Renderer;
};

}

#endif
