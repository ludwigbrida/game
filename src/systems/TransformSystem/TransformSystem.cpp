#include "TransformSystem.hpp"
#include "../../components/TransformComponent.hpp"

// TODO: Extract
#include "../../ecs/Registry/Registry.hpp"

void TransformSystem::run(const Registry& registry, float deltaTime) {
	auto entities = registry.view<TransformComponent>();
}
