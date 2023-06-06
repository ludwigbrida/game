#ifndef ENGINE_VERTEX_ARRAY_HPP
#define ENGINE_VERTEX_ARRAY_HPP

#include <Engine/Components/Mesh.hpp>
#include <Engine/Core/Arithmetic.hpp>

namespace ng {

class VertexArray {
public:
	explicit VertexArray(const Mesh& mesh);
	~VertexArray();

	UInt32 vertexArrayLocation;
	Int32 indices;

private:
	UInt32 vertexBufferLocation;
	UInt32 indexBufferLocation;
};

}

#endif
