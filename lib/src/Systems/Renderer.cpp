#include "Renderer.hpp"
#include "Engine/Core/Registry.hpp"
#include <Engine/Components/Transform.hpp>
#include <GL/glew.h>

namespace ng {

void Renderer::update(Registry& registry, State& state, Float deltaTime) {
	auto entities = registry.view<Transform>();

	clear(Color::Black);

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
	}
}

void Renderer::clear(const Color& color) const {
	glClearColor(
		static_cast<Float>(color.r) / 255, static_cast<Float>(color.g) / 255,
		static_cast<Float>(color.b) / 255, static_cast<Float>(color.a) / 255);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Mesh& mesh, const Matrix4f& modelMatrix) const {}

}
