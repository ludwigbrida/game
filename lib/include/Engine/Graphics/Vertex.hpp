#ifndef ENGINE_VERTEX_HPP
#define ENGINE_VERTEX_HPP

#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace ng {

struct Vertex {
	Vector3f position;
	Vector3f normal;
	Color color;
};

}

#endif
