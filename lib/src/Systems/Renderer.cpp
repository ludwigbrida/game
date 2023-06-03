#include "Renderer.hpp"
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Perspective.hpp>
#include <Engine/Core/Registry.hpp>
#include <GL/glew.h>

namespace ng {

void Renderer::update(Registry& registry, State& state, Float deltaTime) {
	clear(Color::Black);

	auto& cameraMatrices = registry.get<Matrices>(state.activeCamera);
	auto& cameraPerspective = registry.get<Perspective>(state.activeCamera);

	projectionMatrix = Matrix4f::fromPerspective(cameraPerspective);
	viewMatrix = cameraMatrices.world.inverted();

	auto entities = registry.view<Matrices, Mesh>();

	for (auto entity : entities) {
		auto& matrices = registry.get<Matrices>(entity);
		auto& mesh = registry.get<Mesh>(entity);

		if (!targets.contains(entity)) {
			auto vertexArray = std::make_unique<VertexArray>(mesh);
			targets.insert({entity, std::move(vertexArray)});
		}

		// TODO
		Program program{R"(
#version 410 core

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
#version 410 core

in vec3 fragmentColor;

out vec4 color;

void main() {
	color = vec4(fragmentColor, 1);
}
)"};

		const auto& target = targets[entity];

		draw(*target, program, matrices.world);
	}
}

void Renderer::clear(const Color& color) const {
	glClearColor(
		static_cast<Float>(color.r) / 255, static_cast<Float>(color.g) / 255,
		static_cast<Float>(color.b) / 255, static_cast<Float>(color.a) / 255);

	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const VertexArray& vertexArray, const Program& program,
										const Matrix4f& modelMatrix) const {
	glUseProgram(program.location);

	glUniformMatrix4fv(program.modelMatrixLocation, 1, false, modelMatrix);
	glUniformMatrix4fv(program.viewMatrixLocation, 1, false, viewMatrix);
	glUniformMatrix4fv(program.projectionMatrixLocation, 1, false,
										 projectionMatrix);

	glBindVertexArray(vertexArray.vertexArrayLocation);

	glDrawElements(GL_TRIANGLES, vertexArray.indices, GL_UNSIGNED_INT, nullptr);

	glBindVertexArray(0);
}

}
