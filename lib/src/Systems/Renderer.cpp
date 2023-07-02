#include "Renderer.hpp"
#include <Engine/Components/Camera.hpp>
#include <Engine/Components/Matrices.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>
#include <GL/glew.h>

namespace Engine {

Renderer::Renderer() {
	skyboxVertexArray = std::make_unique<VertexArrayCube>(Mesh::createSkybox());
	skyboxShader = std::make_unique<Shader>("assets/shaders/skybox");
	skyboxTexture = std::make_unique<TextureCube>("assets/skybox");

	auto material0 = std::make_unique<Material>(
		"assets/shaders/mesh",
		"assets/skybox/front.jpg"
	);
	auto material1 =
		std::make_unique<Material>("assets/shaders/mesh", "assets/skybox/back.jpg");

	materials.insert({0, std::move(material0)});
	materials.insert({1, std::move(material1)});

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::run(Registry& registry, State& state, const Clock& clock) {
	clear(Color::White);

	const auto& cameraTransform = registry.get<Transform>(state.activeCamera);
	const auto& cameraPerspective = registry.get<Camera>(state.activeCamera);

	const auto cameraMatrix = Matrix4<Float>::fromLookAt(
		cameraTransform.position,
		cameraTransform.position + cameraPerspective.forward,
		Vector3<Float>::Up
	);

	projectionMatrix = Matrix4<Float>::fromPerspective(cameraPerspective);
	viewMatrix = cameraMatrix.inverted();

	const auto entities = registry.view<Transform, Mesh>();

	drawSkybox();

	for (const auto entity: entities) {
		const auto& transform = registry.get<Transform>(entity);
		const auto& mesh = registry.get<Mesh>(entity);

		if (!targets.contains(entity)) {
			auto vertexArray = std::make_unique<VertexArray>(mesh);
			targets.insert({entity, std::move(vertexArray)});
		}

		const auto& target = targets[entity];
		const auto& material = materials[mesh.materialId];

		const auto modelMatrix = Matrix4<Float>::fromTransform(transform);

		draw(*target, *material, modelMatrix);
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
	const Material& material,
	const Matrix4<Float>& modelMatrix
) const {
	material.shader->bind();

	material.diffuse->bind();

	material.shader->use("modelMatrix", modelMatrix);
	material.shader->use("viewMatrix", viewMatrix);
	material.shader->use("projectionMatrix", projectionMatrix);
	material.shader->use("diffuseTexture", material.diffuse->textureId);

	vertexArray.bind();

	glDrawElements(GL_TRIANGLES, vertexArray.indices, GL_UNSIGNED_INT, nullptr);

	vertexArray.unbind();

	material.diffuse->unbind();

	material.shader->unbind();
}

void Renderer::drawSkybox() const {
	glDepthMask(GL_FALSE);

	skyboxShader->bind();

	skyboxTexture->bind();

	auto viewMatrixWithoutPosition = viewMatrix;
	viewMatrixWithoutPosition.m30 = 0;
	viewMatrixWithoutPosition.m31 = 0;
	viewMatrixWithoutPosition.m32 = 0;

	skyboxShader->use("viewMatrix", viewMatrixWithoutPosition);
	skyboxShader->use("projectionMatrix", projectionMatrix);

	skyboxVertexArray->bind();

	glDrawArrays(GL_TRIANGLES, 0, 36);

	skyboxVertexArray->unbind();

	skyboxTexture->unbind();

	skyboxShader->unbind();

	glDepthMask(GL_TRUE);
}

}
