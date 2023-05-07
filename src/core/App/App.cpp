#include "App.hpp"
#include "../../components/MeshComponent.hpp"
#include "../../components/TransformComponent.hpp"
#include "../../systems/RenderSystem/RenderSystem.hpp"
#include "../../systems/TransformSystem/TransformSystem.hpp"

App::App() {
	glfwInit();

	window = glfwCreateWindow(640, 480, "App", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	glClearColor(0.25, 0.25, 0.75, 1);

	registry.addSystem<TransformSystem>();
	registry.addSystem<RenderSystem>();

	registry.addComponent<TransformComponent>(0, {});
	registry.addComponent<TransformComponent>(1, {});

	registry.addComponent<MeshComponent>(0, MeshComponent::createTriangle(1));
}

void App::run() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		registry.run(0);

		glfwSwapBuffers(window);
	}
}

App::~App() { glfwTerminate(); }
