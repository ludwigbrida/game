#include "Shader.hpp"
#include "Platform/File.hpp"
#include <GL/glew.h>
#include <iostream>

namespace Engine {

Shader::Shader(const std::string& path): programId{0} {
	std::string vertexPath = path + "/vertex.glsl";
	std::string fragmentPath = path + "/fragment.glsl";

	std::string vertexSource = File::Read(vertexPath);
	std::string fragmentSource = File::Read(fragmentPath);

	compile(vertexSource.c_str(), fragmentSource.c_str());
}

Shader::Shader(const char* vertexSource, const char* fragmentSource)
		: programId{0} {
	compile(vertexSource, fragmentSource);
}

void Shader::compile(const char* vertexSource, const char* fragmentSource) {
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

void Shader::bind() const {
	glUseProgram(programId);
}

void Shader::unbind() const {
	glUseProgram(0);
}

void Shader::use(const char* name, UInt32 value) const {
	auto uniformId = glGetUniformLocation(programId, name);
	glUniform1ui(uniformId, value);
}

void Shader::use(const char* name, const Vector3<Float>& value) const {
	auto uniformId = glGetUniformLocation(programId, name);
	glUniform3fv(uniformId, 1, value);
}

void Shader::use(const char* name, const Matrix4<Float>& value) const {
	auto uniformId = glGetUniformLocation(programId, name);
	glUniformMatrix4fv(uniformId, 1, GL_FALSE, value);
}

Shader::~Shader() {
	glDeleteProgram(programId);
}

}
