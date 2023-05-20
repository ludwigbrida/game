#include "shader.hpp"
#include <fstream>
#include <sstream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
	std::string vertexSource;
	std::string fragmentSource;

	std::ifstream vertexFile;
	std::ifstream fragmentFile;

	vertexFile.open(vertexPath);
	fragmentFile.open(fragmentPath);

	std::stringstream vertexStream, fragmentStream;

	vertexStream << vertexFile.rdbuf();
	fragmentStream << fragmentFile.rdbuf();

	vertexFile.close();
	fragmentFile.close();

	vertexSource = vertexStream.str();
	fragmentSource = fragmentStream.str();
}
