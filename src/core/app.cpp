#include "app.hpp"
#include "../components/mesh.hpp"
#include "../components/perspective.hpp"
#include "../components/transform.hpp"
#include "../systems/renderer.hpp"
#include "../systems/transformer.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

App::App() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	window = glfwCreateWindow(width, height, "Game", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	GLenum error = glewInit();

	if (error != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(error));
		exit(1);
	}

	glViewport(0, 0, width, height);

	registry.activate<Transformer>();
	registry.activate<Renderer>();

	// Player
	registry.add<Transform>(0, {});
	registry.add<Perspective>(0, {});

	// Triangle
	registry.add<Transform>(1, {});
	registry.add<Mesh>(1, Mesh::createTriangle(1));
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
