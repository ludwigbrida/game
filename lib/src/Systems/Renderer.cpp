#include "Renderer.hpp"
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Perspective.hpp>
#include <Engine/Core/Registry.hpp>
#include <GL/glew.h>
#include <iostream>

namespace ng {

Renderer::Renderer(): texture{"assets/skybox/front.jpg"} {}

void Renderer::setup() {
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	std::cout << "Init" << std::endl;
}

void Renderer::update(Registry& registry, State& state, const Clock& clock) {
	clear(Color::Black);

	auto& cameraMatrices = registry.get<Matrices>(state.activeCamera);
	auto& cameraPerspective = registry.get<Perspective>(state.activeCamera);

	projectionMatrix = Matrix4<Float>::fromPerspective(cameraPerspective);
	viewMatrix = cameraMatrices.world.inverted();

	auto entities = registry.view<Matrices, Mesh>();

	for (auto entity: entities) {
		auto& matrices = registry.get<Matrices>(entity);
		auto& mesh = registry.get<Mesh>(entity);

		if (!targets.contains(entity)) {
			auto vertexArray = std::make_unique<VertexArray>(mesh);
			targets.insert({entity, std::move(vertexArray)});
		}

		Shader shader{
			R"(
#version 410 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout (location = 0) in vec3 vertexPosition;
layout (location = 2) in vec3 vertexColor;
layout (location = 3) in vec2 vertexTexCoord;

out vec3 fragmentColor;
out vec2 fragmentTexCoord;

void main() {
	fragmentColor = vertexColor;
	fragmentTexCoord = vertexTexCoord;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition, 1);
}
)",
			R"(
#version 410 core

in vec3 fragmentColor;
in vec2 fragmentTexCoord;

out vec4 color;

void main() {
	color = vec4(fragmentColor, 1);
}
)"};

		const auto& target = targets[entity];

		draw(*target, shader, matrices.world);
	}
}

void Renderer::clear(const Color& color) const {
	glClearColor(
		static_cast<Float>(color.r) / 255,
		static_cast<Float>(color.g) / 255,
		static_cast<Float>(color.b) / 255,
		static_cast<Float>(color.a) / 255
	);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(
	const VertexArray& vertexArray,
	const Shader& shader,
	const Matrix4<Float>& modelMatrix
) const {
	shader.bind();

	shader.upload("modelMatrix", modelMatrix);
	shader.upload("viewMatrix", viewMatrix);
	shader.upload("projectionMatrix", projectionMatrix);

	glBindVertexArray(vertexArray.vertexArrayId);

	glDrawElements(GL_TRIANGLES, vertexArray.indices, GL_UNSIGNED_INT, nullptr);

	glBindVertexArray(0);

	shader.unbind();
}

}
