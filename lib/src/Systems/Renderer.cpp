#include "Renderer.hpp"
#include "Engine/Core/Registry.hpp"
#include <Engine/Components/Transform.hpp>

namespace ng {

void Renderer::update(Registry& registry, State& state, float deltaTime) {
	auto entities = registry.view<Transform>();

	for (auto entity : entities) {
		auto& transform = registry.get<Transform>(entity);
	}
}

void Renderer::clear(const Color& color) const {}

void Renderer::draw(const Mesh& mesh, const Matrix4f& modelMatrix) const {}

}
