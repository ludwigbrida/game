#include "Shader.hpp"
#include <iostream>

namespace ng {

Shader::Shader(GLenum type, const char* source) {
	location = create(type, source);
}

UInt32 Shader::create(GLenum type, const char* source) {
	auto shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	Int32 success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cerr << infoLog << std::endl;
	}

	return shader;
}

}
