#include "app.hpp"
#include "../components/mesh.hpp"
#include "../components/transform.hpp"
#include "../systems/render-system.hpp"
#include "../systems/transform-system.hpp"

App::App() {
	glfwInit();

	window = glfwCreateWindow(640, 480, "Game", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	glClearColor(0.25, 0.25, 0.75, 1);

	registry.addSystem<TransformSystem>();
	registry.addSystem<RenderSystem>();

	registry.addComponent<Transform>(0, {});
	registry.addComponent<Transform>(1, {});

	registry.addComponent<Mesh>(0, Mesh::createTriangle(1));
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
