#ifndef GAME_MATERIAL_HPP
#define GAME_MATERIAL_HPP

#include "Texture.hpp"

namespace ng {

class Material {
	Texture* diffuse;
	Texture* normal;
};

}

#endif
