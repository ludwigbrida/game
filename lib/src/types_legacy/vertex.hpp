#ifndef GAME_VERTEX_HPP
#define GAME_VERTEX_HPP

#include "../math/vector.hpp"
#include <Engine/Graphics/Color.hpp>

struct Vertex {
	Vector3f position;
	Vector3f normal;
	ng::Color color;
};

#endif
