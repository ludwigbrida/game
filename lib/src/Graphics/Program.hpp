#ifndef ENGINE_PROGRAM_HPP
#define ENGINE_PROGRAM_HPP

#include "Shader.hpp"

namespace ng {

class Program {
public:
	Program(const char* vertexSource, const char* fragmentSource);

	UInt32 location;

private:
	Shader vertexShader;
	Shader fragmentShader;

	static UInt32 create(UInt32 vertexLocation, UInt32 fragmentLocation);
};

}

#endif
