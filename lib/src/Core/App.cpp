#include "../Systems/Collision.hpp"
#include "../Systems/Renderer.hpp"
#include "../Systems/Transformer.hpp"
#include <Engine/Components/Collider.hpp>
#include <Engine/Components/Matrices.hpp>
#include <Engine/Components/Perspective.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/App.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Input/Keyboard.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>

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

	Keyboard::setup(window);

	registry.activate<Transformer>();
	registry.activate<Collision>();
	registry.activate<Renderer>();

	// TODO: disabled vsync
	// glfwSwapInterval(0);
}

void App::run() {
	registry.setup();

	Float previousTime = 0;

	while (!glfwWindowShouldClose(window)) {
		clock.elapsedTime = static_cast<Float>(glfwGetTime());
		clock.deltaTime = clock.elapsedTime - previousTime;
		previousTime = clock.elapsedTime;

		std::stringstream title;
		title << "Game [" << static_cast<UInt32>(1 / clock.deltaTime) << " fps]";

		glfwSetWindowTitle(window, title.str().c_str());

		glfwPollEvents();

		glViewport(0, 0, width, height);

		registry.run(state, clock);

		glfwSwapBuffers(window);
	}
}

App::~App() {
	glfwTerminate();
}

}
