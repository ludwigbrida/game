#include "Renderer.hpp"
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Perspective.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>
#include <GL/glew.h>

namespace Engine {

Renderer::Renderer()
		: shader{"assets/shaders/mesh"}, texture{"assets/skybox/front.jpg"} {
	auto material0 =
		std::make_unique<Material>(Texture("assets/skybox/front.jpg"));
	auto material1 =
		std::make_unique<Material>(Texture("assets/skybox/back.jpg"));

	materials.insert({0, std::move(material0)});
	materials.insert({1, std::move(material1)});

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::run(Registry& registry, State& state, const Clock& clock) {
	clear(Color::White);

	auto& cameraTransform = registry.get<Transform>(state.activeCamera);
	auto& cameraPerspective = registry.get<Perspective>(state.activeCamera);

	auto cameraMatrix = Matrix4<Float>::fromTransform(cameraTransform);

	projectionMatrix = Matrix4<Float>::fromPerspective(cameraPerspective);
	viewMatrix = cameraMatrix.inverted();

	auto entities = registry.view<Transform, Mesh>();

	for (auto entity: entities) {
		auto& transform = registry.get<Transform>(entity);
		auto& mesh = registry.get<Mesh>(entity);

		if (!targets.contains(entity)) {
			auto vertexArray = std::make_unique<VertexArray>(mesh);
			targets.insert({entity, std::move(vertexArray)});
		}

		const auto& target = targets[entity];
		const auto& material = materials[mesh.materialId];

		auto modelMatrix = Matrix4<Float>::fromTransform(transform);

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
	// texture.bind();
	shader.bind();
	material.diffuse.bind();

	shader.upload("modelMatrix", modelMatrix);
	shader.upload("viewMatrix", viewMatrix);
	shader.upload("projectionMatrix", projectionMatrix);
	shader.upload("diffuseTexture", material.diffuse.textureId);

	vertexArray.bind();

	glDrawElements(GL_TRIANGLES, vertexArray.indices, GL_UNSIGNED_INT, nullptr);

	vertexArray.unbind();

	material.diffuse.unbind();
	shader.unbind();
}
}
