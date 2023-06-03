#include "VertexArray.hpp"
#include <GL/glew.h>

namespace ng {

VertexArray::VertexArray(const Mesh& mesh) {
	glGenVertexArrays(1, &vertexArrayLocation);
	glBindVertexArray(vertexArrayLocation);

	glGenBuffers(1, &vertexBufferLocation);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferLocation);
	glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(Float),
							 mesh.vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(Float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(Float),
												(void*)(3 * sizeof(Float)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(Float),
												(void*)(6 * sizeof(Float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &indexBufferLocation);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferLocation);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(UInt32),
							 mesh.indices.data(), GL_STATIC_DRAW);

	indices = mesh.indices.size();

	glBindVertexArray(0);
}

VertexArray::~VertexArray() {
	glDeleteBuffers(1, &vertexBufferLocation);
	glDeleteBuffers(1, &indexBufferLocation);
	glDeleteVertexArrays(1, &vertexArrayLocation);
}

}
