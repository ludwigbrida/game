#include "Renderer.hpp"
#include "Engine/Core/Registry.hpp"
#include <Engine/Components/Transform.hpp>
#include <GL/glew.h>

namespace ng {

void Renderer::update(Registry& registry, State& state, Float deltaTime) {
	auto entities = registry.view<Transform, Mesh>();

	clear(Color::Black);

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
		auto& mesh = registry.get<Mesh>(entity);

		auto modelMatrix = Matrix4f::fromTransform(transform);

		// TODO
		Program program{R"(
#version 410 core_legacy

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout (location = 0) in vec3 vertexPosition;
layout (location = 2) in vec3 vertexColor;

out vec3 fragmentColor;

void main() {
	fragmentColor = vertexColor;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1);
}
)",
										R"(
#version 410 core_legacy

in vec3 fragmentColor;

out vec4 color;

void main() {
	color = vec4(fragmentColor, 1);
}
)"};

		draw(mesh, program, modelMatrix);
	}
}

void Renderer::clear(const Color& color) const {
	glClearColor(
		static_cast<Float>(color.r) / 255, static_cast<Float>(color.g) / 255,
		static_cast<Float>(color.b) / 255, static_cast<Float>(color.a) / 255);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Mesh& mesh, const Program& program,
										const Matrix4f& modelMatrix) const {
	// TODO
	glUniformMatrix4fv(program.modelMatrixLocation, 1, false, modelMatrix);
	glUniformMatrix4fv(program.viewMatrixLocation, 1, false, {});
	glUniformMatrix4fv(program.projectionMatrixLocation, 1, false, {});
}

}
