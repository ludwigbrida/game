#include "app.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../systems/renderer.hpp"
#include "../systems/transformer.hpp"

App::App() {
	glfwInit();

	window = glfwCreateWindow(width, height, "Game", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	glViewport(0, 0, width, height);

	registry.activate<Transformer>();
	registry.activate<Renderer>();

	registry.add<Transform>(0, {});
	registry.add<Transform>(1, {});

	registry.add<Mesh>(0, Mesh::createTriangle(1));
}

void App::run() {
	registry.setup();

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		registry.update(0);

		glfwSwapBuffers(window);
	}
}

App::~App() { glfwTerminate(); }
