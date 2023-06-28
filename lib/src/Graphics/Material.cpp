#include "Material.hpp"

namespace Engine {

Material::Material(
	const std::string& shaderPath,
	const std::string& diffusePath
) {
	shader = std::make_unique<Shader>(shaderPath);
	diffuse = std::make_unique<Texture>(diffusePath);
}

}
