#version 410 core

uniform sampler2D diffuseTexture;

in vec3 fragmentColor;
in vec2 fragmentTexCoord;

out vec4 color;

void main() {
	color = vec4(fragmentColor, 1);
	// color = texture(diffuseTexture, fragmentTexCoord);
}
