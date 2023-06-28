#ifndef ENGINE_MATERIAL_HPP
#define ENGINE_MATERIAL_HPP

#include "Texture.hpp"

namespace Engine {

class Material {
public:
	explicit Material(const Texture& diffuse);

private:
	Texture diffuse;

	friend class Renderer;
};

}

#endif
