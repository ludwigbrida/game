#include "VertexArray.hpp"
#include <GL/glew.h>

namespace ng {

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

}
