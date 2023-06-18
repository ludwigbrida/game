#include "Texture.hpp"
#include <GL/glew.h>
#include <iostream>
#include <stb_image.h>

namespace ng {

Texture::Texture(const std::string& source): textureId{0} {
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(
		GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data;

	data = stbi_load(source.c_str(), &width, &height, &nrChannels, 0);

	if (data) {
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGB,
			width,
			height,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			data
		);

		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
		std::cout << "Could not load texture" << std::endl;
	}

	stbi_image_free(data);
}

Texture::~Texture() {
	glDeleteTextures(1, &textureId);
}

}
