#ifndef ENGINE_MATERIAL_HPP
#define ENGINE_MATERIAL_HPP

#include "Texture.hpp"

namespace ng {

class Material {
public:
	explicit Material(const Texture& diffuse);

private:
	Texture diffuse;
};

}

#endif
