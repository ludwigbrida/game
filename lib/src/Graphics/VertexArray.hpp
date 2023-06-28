#ifndef ENGINE_VERTEX_ARRAY_HPP
#define ENGINE_VERTEX_ARRAY_HPP

#include <Engine/Components/Mesh.hpp>
#include <Engine/Core/Arithmetic.hpp>

namespace Engine {

class VertexArray {
public:
	explicit VertexArray(const Mesh& mesh);
	~VertexArray();

	void bind() const;
	void unbind() const;

	UInt32 vertexArrayId;
	Int32 indices;

private:
	UInt32 vertexBufferId;
	UInt32 indexBufferId;
};

}

#endif
