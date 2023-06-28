#include "Material.hpp"

namespace Engine {

Material::Material(const std::string& diffusePath) {
	diffuse = std::make_unique<Texture>(diffusePath);
}

}
