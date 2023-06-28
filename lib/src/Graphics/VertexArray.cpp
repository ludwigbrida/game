#include "VertexArray.hpp"
#include <GL/glew.h>

namespace Engine {

VertexArray::VertexArray(const Mesh& mesh)
		: vertexBufferId{0}, indexBufferId{0}, vertexArrayId{0} {
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(Float), (void*)0);
	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		11 * sizeof(Float),
		(void*)(3 * sizeof(Float))
	);
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_FALSE,
		11 * sizeof(Float),
		(void*)(6 * sizeof(Float))
	);
	glVertexAttribPointer(
		3,
		2,
		GL_FLOAT,
		GL_FALSE,
		11 * sizeof(Float),
		(void*)(9 * sizeof(Float))
	);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	glGenBuffers(1, &indexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		mesh.indices.size() * sizeof(UInt32),
		mesh.indices.data(),
		GL_STATIC_DRAW
	);

	indices = mesh.indices.size();

	glBindVertexArray(0);
}

void VertexArray::bind() const {
	glBindVertexArray(vertexArrayId);
}

void VertexArray::unbind() const {
	glBindVertexArray(0);
}

VertexArray::~VertexArray() {
	glDeleteBuffers(1, &vertexBufferId);
	glDeleteBuffers(1, &indexBufferId);
	glDeleteVertexArrays(1, &vertexArrayId);
}

}
