#include <Engine/Core/Window.hpp>
#include <Engine/Input/Keyboard.hpp>
#include <Engine/Input/Mouse.hpp>
#include <cstdio>
#include <cstdlib>

namespace Engine {

void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

Window::Window(Int32 width, Int32 height) {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	window = glfwCreateWindow(width, height, "", nullptr, nullptr);

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

	GLenum status = glewInit();

	if (status != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(status));
		exit(1);
	}

	glfwSwapInterval(0);

	Keyboard::setup(window);
	Mouse::setup(window);
}

void Window::setTitle(String title) {
	glfwSetWindowTitle(window, title);
}

bool Window::isOpen() const {
	return !glfwWindowShouldClose(window);
}

void Window::pollEvents() const {
	glfwPollEvents();
}

void Window::swapBuffers() const {
	glfwSwapBuffers(window);
}

Window::~Window() {
	glfwTerminate();
}

}
