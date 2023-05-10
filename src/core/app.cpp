#include "app.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../systems/render-system.hpp"
#include "../systems/transform-system.hpp"

App::App() {
	glfwInit();

	window = glfwCreateWindow(width, height, "Game", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	glViewport(0, 0, width, height);

	registry.activate<TransformSystem>();
	registry.activate<RenderSystem>();

	registry.add<Transform>(0, {});
	registry.add<Transform>(1, {});

	registry.add<Mesh>(0, Mesh::createTriangle(1));
}

void App::run() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		registry.run(0);

		glfwSwapBuffers(window);
	}
}

App::~App() { glfwTerminate(); }
