#include <Engine/Input/Mouse.hpp>

namespace Engine::Mouse {

void callback(GLFWwindow* window, double positionX, double positionY) {}

void setup(GLFWwindow* window) {
	glfwSetCursorPosCallback(window, callback);
	// glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

}
