#ifndef ENGINE_MATERIAL_HPP
#define ENGINE_MATERIAL_HPP

#include "Texture.hpp"
#include <memory>

namespace Engine {

class Material {
public:
	explicit Material(const std::string& diffusePath);

private:
	std::unique_ptr<Texture> diffuse;

	friend class Renderer;
};

}

#endif
