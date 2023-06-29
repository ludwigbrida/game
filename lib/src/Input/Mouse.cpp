#include <Engine/Input/Mouse.hpp>

namespace Engine::Mouse {

void cursorPositionCallback(
	GLFWwindow* window,
	double positionX,
	double positionY
) {}

void cursorEnterCallback(GLFWwindow* window, int entered) {}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {}
}

void setup(GLFWwindow* window) {
	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetCursorEnterCallback(window, cursorEnterCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	// glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

}
