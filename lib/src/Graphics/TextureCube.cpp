#include "TextureCube.hpp"
#include <GL/glew.h>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

namespace Engine {

TextureCube::TextureCube(const std::string& path): textureId{0} {
	const std::vector<std::string> faces = {
		path + "/right.jpg",
		path + "/left.jpg",
		path + "/top.jpg",
		path + "/bottom.jpg",
		path + "/back.jpg",
		path + "/front.jpg",
	};

	int width, height, channels;
	unsigned char* data;

	stbi_set_flip_vertically_on_load(1);

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	for (UInt32 i = 0; i < faces.size(); i++) {
		data = stbi_load(faces[i].c_str(), &width, &height, &channels, 0);

		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
			0,
			GL_RGB,
			width,
			height,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			data
		);
	}

	stbi_image_free(data);
}

void TextureCube::bind() const {
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);
}

void TextureCube::unbind() const {
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

TextureCube::~TextureCube() {
	glDeleteTextures(1, &textureId);
}

}
