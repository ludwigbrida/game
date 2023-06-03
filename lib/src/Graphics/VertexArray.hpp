#ifndef GAME_VERTEX_ARRAY_HPP
#define GAME_VERTEX_ARRAY_HPP

#include <Engine/Components/Mesh.hpp>
#include <Engine/Core/Arithmetic.hpp>

namespace ng {

class VertexArray {
public:
	VertexArray() = default;
	explicit VertexArray(const Mesh& mesh);
	~VertexArray();

	UInt32 data;
	Int32 indices;

private:
	static UInt32 create();
	static UInt32 createBuffer();
};

}

#endif
