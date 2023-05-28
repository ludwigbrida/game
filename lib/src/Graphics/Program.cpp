#include "Program.hpp"
#include <iostream>

namespace ng {

Program::Program(const char* vertexSource, const char* fragmentSource)
		: vertexShader{GL_VERTEX_SHADER, vertexSource},
			fragmentShader{GL_FRAGMENT_SHADER, fragmentSource} {
	location = create(vertexShader.location, fragmentShader.location);
}

UInt32 Program::create(UInt32 vertexLocation, UInt32 fragmentLocation) {
	auto program = glCreateProgram();
	glAttachShader(program, vertexLocation);
	glAttachShader(program, fragmentLocation);
	glLinkProgram(program);

	Int32 success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		std::cerr << infoLog << std::endl;
	}

	glDeleteShader(vertexLocation);
	glDeleteShader(fragmentLocation);
	return program;
}

}
