#ifndef GAME_VERTEX_ARRAY_HPP
#define GAME_VERTEX_ARRAY_HPP

#include <Engine/Core/Arithmetic.hpp>

namespace ng {

class VertexArray {
public:
	UInt32 data;

private:
	static UInt32 create();
	static UInt32 createBuffer();
};

}

#endif
