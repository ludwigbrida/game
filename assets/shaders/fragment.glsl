#version 420 core

precision highp float;

in vec3 fragmentNormal;
in vec3 fragmentColor;

uniform vec3 sunDirection;

out vec4 color;

void main() {
	vec3 surfaceNormal = normalize(fragmentNormal);

	vec3 sunColor = vec3(1, 0.95, 0.9);

	float ambientIntensity = 0.25;
	vec3 ambient = sunColor * ambientIntensity;

	float directionalIntensity = max(dot(surfaceNormal, -sunDirection), .0);
	vec3 directional = sunColor * directionalIntensity;

	vec3 light = ambient + directional;

	color = vec4(vec3(1, 1, 1) * light, 1);
}
