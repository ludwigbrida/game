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
#include <Engine/Maths/Radian.hpp>
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

	// Player
	registry.add<Transform>(0, {.position{0, 0, 0}});
	registry.add<Matrices>(0);
	registry.add<Perspective>(
		0,
		{.fieldOfView = fromDegrees(45),
		 .aspectRatio = 16. / 9,
		 .near = 0.1,
		 .far = 1000}
	);
	// TODO: Maybe does not work with triangles?
	registry.add<Collider>(
		0,
		{.vertices{
			// Top
			{-1, 1, -1},
			{1, 1, -1},
			{-1, 1, 1},
			{1, 1, 1},
			// Bottom
			{-1, -1, -1},
			{1, -1, -1},
			{-1, -1, 1},
			{1, -1, 1},
		}}
	);

	// Triangle
	registry.add<Transform>(1, {.position{0, 0, 0}});
	registry.add<Matrices>(1);
	registry.add<Mesh>(1, Mesh::createTriangle(1));
	registry.add<Collider>(
		1,
		{.vertices{
			// Top
			{-1, 1, -1},
			{1, 1, -1},
			{-1, 1, 1},
			{1, 1, 1},
			// Bottom
			{-1, -1, -1},
			{1, -1, -1},
			{-1, -1, 1},
			{1, -1, 1},
		}}
	);

	// Cube
	registry.add<Transform>(
		2,
		{.position{1, 0, -2},
		 .rotation{
			 Quaternion<Float>::fromAxisAngle(Vector3<Float>::Up, fromDegrees(25))}}
	);
	registry.add<Matrices>(2);
	registry.add<Mesh>(2, Mesh::createCube(1));

	state.activeCamera = 0;

	// TODO: disabled vsync
	// glfwSwapInterval(0);
}

void App::run() {
	registry.setup();

	Float previousTime = 0;

	while (!glfwWindowShouldClose(window)) {
		auto elapsedTime = static_cast<Float>(glfwGetTime());
		auto deltaTime = elapsedTime - previousTime;
		previousTime = elapsedTime;

		std::stringstream title;
		title << "Game [" << static_cast<UInt32>(1 / deltaTime) << " fps]";

		glfwSetWindowTitle(window, title.str().c_str());

		glfwPollEvents();

		glViewport(0, 0, width, height);

		registry.run(state, deltaTime, elapsedTime);

		glfwSwapBuffers(window);
	}
}

App::~App() {
	glfwTerminate();
}

}
