#include "../Systems/Renderer.hpp"
#include "Engine/Core/Registry.hpp"
#include <Engine/Components/Perspective.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/App.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace ng {

App::App() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	window = glfwCreateWindow(width, height, "Game", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	GLenum error = glewInit();

	if (error != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(error));
		exit(1);
	}

	// registry.activate<Transformer>();
	registry.activate<Renderer>();

	// Player
	registry.add<Transform>(0, {.position{0, 0, 0}});
	registry.add<Perspective>(0, {.fieldOfView = 45, .aspectRatio = 16. / 9});

	// Object 1
	registry.add<Transform>(1, {.position{5, 0, -3}});
	// registry.add<Mesh>(1, Mesh::createTriangle(1));

	// Object 2
	registry.add<Transform>(2, {.position{0, 0, 0}});
	// registry.add<Mesh>(2, Mesh::createTriangle(4));

	state.activeCamera = 0;
}

void App::run() {
	registry.setup();

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glViewport(0, 0, width, height);

		registry.update(state, 0);

		glfwSwapBuffers(window);
	}
}

App::~App() { glfwTerminate(); }

}
