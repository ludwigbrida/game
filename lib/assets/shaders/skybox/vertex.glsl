#version 410 core

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout (location = 0) in vec3 vertexTexCoord;

out vec3 fragmentTexCoord;

void main() {
	// fragmentTexCoord = vertexTexCoord;
	fragmentTexCoord = vec3(vertexTexCoord.x, vertexTexCoord.y, -vertexTexCoord.z);
	vec4 position = projectionMatrix * viewMatrix * vec4(vertexTexCoord, 1);
	gl_Position = vec4(position.x, position.y, position.w, position.w);
}
