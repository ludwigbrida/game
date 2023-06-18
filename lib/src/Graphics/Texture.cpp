#include "Texture.hpp"
#include <GL/glew.h>
#include <iostream>
#include <stb_image.h>

namespace ng {

Texture::Texture(const std::string& source): textureId{0} {
	int width, height, channels;
	unsigned char* data;

	data = stbi_load(source.c_str(), &width, &height, &channels, 0);

	if (!data) {
		std::cerr << "Could not load image data" << std::endl;
	}

	glCreateTextures(GL_TEXTURE_2D, 1, &textureId);
	glTextureStorage2D(textureId, 1, GL_RGB8, width, height);

	glTextureParameteri(textureId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameteri(textureId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTextureSubImage2D(
		textureId,
		0,
		0,
		0,
		width,
		height,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		data
	);

	stbi_image_free(data);
}

void Texture::bind() const {
	glBindTextureUnit(0, textureId);
}

Texture::~Texture() {
	glDeleteTextures(1, &textureId);
}

}
