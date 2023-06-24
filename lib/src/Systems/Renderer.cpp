#include "Renderer.hpp"
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Perspective.hpp>
#include <Engine/Core/Registry.hpp>
#include <GL/glew.h>

namespace Engine {

Renderer::Renderer()
		: shader{"assets/shaders/mesh"}, texture{"assets/skybox/front.jpg"} {
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::run(Registry& registry, State& state, const Clock& clock) {
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

		const auto& target = targets[entity];

		draw(*target, matrices.world);
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
	const Matrix4<Float>& modelMatrix
) const {
	shader.bind();
	texture.bind();

	shader.upload("modelMatrix", modelMatrix);
	shader.upload("viewMatrix", viewMatrix);
	shader.upload("projectionMatrix", projectionMatrix);
	shader.upload("diffuseTexture", 0);

	glBindVertexArray(vertexArray.vertexArrayId);

	glDrawElements(GL_TRIANGLES, vertexArray.indices, GL_UNSIGNED_INT, nullptr);

	glBindVertexArray(0);

	shader.unbind();
}

}
