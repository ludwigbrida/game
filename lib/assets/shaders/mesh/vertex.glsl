#version 410 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexNormal;
layout (location = 2) in vec3 vertexColor;
layout (location = 3) in vec2 vertexTexCoord;

out vec3 fragmentColor;
out vec2 fragmentTexCoord;

void main() {
	fragmentColor = vertexColor;
	fragmentTexCoord = vertexTexCoord;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1);
}
