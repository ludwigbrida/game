#include "Keyboard.hpp"

namespace ng {

Keyboard::Keyboard(GLFWwindow* window) {
	glfwSetKeyCallback(window, callback);
}

bool Keyboard::isKeyDown(int key) {
	return keys.contains(key) && keys[key];
}

void Keyboard::callback(GLFWwindow* window, int key, int scancode, int action,
												int mods) {
	keys[key] = action != GLFW_RELEASE;
}

}
