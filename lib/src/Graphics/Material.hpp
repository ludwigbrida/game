#ifndef GAME_MATERIAL_HPP
#define GAME_MATERIAL_HPP

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
