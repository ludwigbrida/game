#ifndef ENGINE_VERTEX_HPP
#define ENGINE_VERTEX_HPP

#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace Engine {

struct Vertex {
	Vector3<Float> position;
	Vector3<Float> normal;
	Color color;
};

}

#endif
