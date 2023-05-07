#include "components/TransformComponent.hpp"
#include "ecs/Registry/Registry.hpp"
#include "maths/Vector/Vector.hpp"
#include "systems/TransformSystem/TransformSystem.hpp"
#include <iostream>

int main() {
	auto vec1 = Vector3f(1, 2, 3);
	auto vec2 = Vector3f(3, 2, 1);
	auto dot = vec1.dot(vec2);
	auto length = vec1.length();

	std::cout << "Hello, World! " << dot << ", " << length << std::endl;

	auto registry = Registry();

	registry.addSystem<TransformSystem>();
	// registry.removeSystem<TransformSystem>();

	registry.addComponent<TransformComponent>(0);
	registry.addComponent<TransformComponent>(1);
	// registry.hasComponent<TransformComponent>(0);
	// registry.removeComponent<TransformComponent>(0);

	registry.run(0);
}
