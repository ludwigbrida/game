#version 410 core

uniform samplerCube textureSampler;

in vec3 fragmentTexCoord;

out vec4 color;

void main() {
	color = texture(textureSampler, fragmentTexCoord);
}
