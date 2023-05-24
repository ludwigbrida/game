#ifndef GAME_VERTEX_HPP
#define GAME_VERTEX_HPP

#include "../gfx/Color.hpp"
#include "../math/vector.hpp"

struct Vertex {
	Vector3f position;
	Vector3f normal;
	Color color;
};

#endif
