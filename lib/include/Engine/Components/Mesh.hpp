#ifndef ENGINE_MESH_HPP
#define ENGINE_MESH_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>
#include <vector>

namespace Engine {

struct Mesh: Component {
	std::vector<Float> vertices;
	std::vector<UInt32> indices;
	UInt32 materialId;

	static Mesh createTriangle(Float size, UInt32 materialId);
	static Mesh createCube(Float size, UInt32 materialId);
};

}

#endif
