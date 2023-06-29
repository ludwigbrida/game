#ifndef ENGINE_VERTEX_ARRAY_CUBE_HPP
#define ENGINE_VERTEX_ARRAY_CUBE_HPP

#include <Engine/Components/Mesh.hpp>
#include <Engine/Core/Arithmetic.hpp>

namespace Engine {

class VertexArrayCube {
public:
	explicit VertexArrayCube(const Mesh& mesh);
	~VertexArrayCube();

	void bind() const;
	void unbind() const;

	UInt32 vertexArrayId;

private:
	UInt32 vertexBufferId;
};

}

#endif
