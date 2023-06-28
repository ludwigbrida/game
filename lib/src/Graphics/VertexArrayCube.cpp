#include "VertexArrayCube.hpp"
#include <GL/glew.h>

namespace Engine {

VertexArrayCube::VertexArrayCube(const Mesh& mesh)
		: vertexBufferId{0}, vertexArrayId{0} {
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	glGenBuffers(1, &vertexBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
	glBufferData(
		GL_ARRAY_BUFFER,
		mesh.vertices.size() * sizeof(Float),
		mesh.vertices.data(),
		GL_STATIC_DRAW
	);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(Float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void VertexArrayCube::bind() const {
	glBindVertexArray(vertexArrayId);
}

void VertexArrayCube::unbind() const {
	glBindVertexArray(0);
}

VertexArrayCube::~VertexArrayCube() {
	glDeleteBuffers(1, &vertexBufferId);
	glDeleteVertexArrays(1, &vertexArrayId);
}

}
