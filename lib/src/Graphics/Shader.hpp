#ifndef ENGINE_SHADER_HPP
#define ENGINE_SHADER_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <GL/glew.h>

namespace ng {

class Shader {
public:
	Shader(GLenum type, const char* source);

	UInt32 location;

private:
	static UInt32 create(GLenum type, const char* source);
};

}

#endif
