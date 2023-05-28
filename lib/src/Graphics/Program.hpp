#ifndef ENGINE_PROGRAM_HPP
#define ENGINE_PROGRAM_HPP

#include "Shader.hpp"

namespace ng {

class Program {
private:
	Shader vertexShader;
	Shader fragmentShader;
};

}

#endif
