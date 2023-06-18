#include "NewShader.hpp"
#include <GL/glew.h>
#include <iostream>

namespace ng {

NewShader::NewShader(const char* vertexSource, const char* fragmentSource) {
	programId = glCreateProgram();

	auto vertexId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexId, 1, &vertexSource, nullptr);
	glCompileShader(vertexId);

	Int32 vertexSuccess;
	char vertexInfoLog[512];
	glGetShaderiv(vertexId, GL_COMPILE_STATUS, &vertexSuccess);

	if (!vertexSuccess) {
		glGetShaderInfoLog(vertexId, 512, nullptr, vertexInfoLog);
		std::cerr << vertexInfoLog << std::endl;
	}

	auto fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentId, 1, &fragmentSource, nullptr);
	glCompileShader(fragmentId);

	Int32 fragmentSuccess;
	char fragmentInfoLog[512];
	glGetShaderiv(fragmentId, GL_COMPILE_STATUS, &fragmentSuccess);

	if (!fragmentSuccess) {
		glGetShaderInfoLog(fragmentId, 512, nullptr, fragmentInfoLog);
		std::cerr << fragmentInfoLog << std::endl;
	}

	glAttachShader(programId, vertexId);
	glAttachShader(programId, fragmentId);
	glLinkProgram(programId);

	Int32 programSuccess;
	char programInfoLog[512];
	glGetProgramiv(programId, GL_LINK_STATUS, &programSuccess);

	if (!programSuccess) {
		glGetProgramInfoLog(programId, 512, nullptr, programInfoLog);
		std::cerr << programInfoLog << std::endl;
	}

	glDeleteShader(vertexId);
	glDeleteShader(fragmentId);
}

void NewShader::bind() const {
	glUseProgram(programId);
}

void NewShader::unbind() const {
	glUseProgram(0);
}

NewShader::~NewShader() {
	glDeleteProgram(programId);
}

}
