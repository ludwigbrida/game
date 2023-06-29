#include "Texture.hpp"
#include <GL/glew.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

namespace Engine {

Texture::Texture(const std::string& source): textureId{0} {
	int width, height, channels;
	unsigned char* data;

	stbi_set_flip_vertically_on_load(1);
	data = stbi_load(source.c_str(), &width, &height, &channels, 0);

	if (!data) {
		std::cerr << "Could not load image data" << std::endl;
	}

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

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

	stbi_image_free(data);
}

void Texture::bind() const {
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::unbind() const {
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
	glDeleteTextures(1, &textureId);
}

}
