#include "CubeMap.hpp"
#include <GL/glew.h>

namespace ng {

CubeMap::CubeMap() {
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_CUBE_MAP, id);
}

}
