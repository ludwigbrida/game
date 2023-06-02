#ifndef GAME_RENDER_TARGET_HPP
#define GAME_RENDER_TARGET_HPP

#include "VertexArray.hpp"
#include <Engine/Core/Arithmetic.hpp>

namespace ng {

struct RenderTarget {
	VertexArray vao;
	Int32 indices;
};

}

#endif
