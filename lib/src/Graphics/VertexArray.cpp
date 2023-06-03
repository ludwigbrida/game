#include "VertexArray.hpp"
#include <GL/glew.h>

namespace ng {

VertexArray::VertexArray(const Mesh& mesh) {
	data = create();
	glBindVertexArray(data);

	auto vertexBuffer = createBuffer();
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
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

	auto indexBuffer = createBuffer();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(UInt32),
							 mesh.indices.data(), GL_STATIC_DRAW);

	indices = mesh.indices.size();

	glBindVertexArray(0);
}

UInt32 VertexArray::create() {
	UInt32 vertexArray;
	glGenVertexArrays(1, &vertexArray);
	return vertexArray;
}

UInt32 VertexArray::createBuffer() {
	UInt32 buffer;
	glGenBuffers(1, &buffer);
	return buffer;
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &data);
}

}
