#include "components/MeshComponent.hpp"
#include "components/TransformComponent.hpp"
#include "ecs/Registry/Registry.hpp"
#include "maths/Vector/Vector.hpp"
#include "systems/RenderSystem/RenderSystem.hpp"
#include "systems/TransformSystem/TransformSystem.hpp"
#include <iostream>

#include <GLFW/glfw3.h>

int main() {
	auto vec1 = Vector3f(1, 2, 3);
	auto vec2 = Vector3f(3, 2, 1);
	auto dot = vec1.dot(vec2);
	auto length = vec1.length();

	std::cout << "Hello, World! " << dot << ", " << length << std::endl;

	auto registry = Registry();

	registry.addSystem<TransformSystem>();
	registry.addSystem<RenderSystem>();

	registry.addComponent<TransformComponent>(0, {});
	registry.addComponent<TransformComponent>(1, {});

	registry.addComponent<MeshComponent>(0, MeshComponent::createTriangle(1));

	registry.run(0);

	// Test GLFW

	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Window", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}
