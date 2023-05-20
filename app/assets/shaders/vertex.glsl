#version 420 core

in vec3 vertexPosition;
in vec3 vertexNormal;
in vec3 vertexColor;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 fragmentNormal;
out vec3 fragmentColor;

void main() {
	fragmentNormal = mat3(modelMatrix) * vertexNormal;
	fragmentColor = vertexColor;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1);
}
