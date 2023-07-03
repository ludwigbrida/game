#version 410 core

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout (location = 0) in vec3 vertexTexCoord;

out vec3 fragmentTexCoord;

void main() {
	fragmentTexCoord = vertexTexCoord;
	vec4 position = projectionMatrix * viewMatrix * vec4(vertexTexCoord, 1);
	gl_Position = position.xyww;
}
