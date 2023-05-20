#ifndef GAME_VERTEX_HPP
#define GAME_VERTEX_HPP

#include "../graphics/color.hpp"
#include "../maths/vector.hpp"

struct Vertex {
	Vector3f position;
	Vector3f normal;
	Color color;
};

#endif
