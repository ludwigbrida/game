#ifndef ENGINE_MESH_HPP
#define ENGINE_MESH_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>
#include <vector>

namespace ng {

struct Mesh : Component {
	std::vector<Float> vertices;
	std::vector<UInt32> indices;

	static Mesh createTriangle(Float size);
};

}

#endif