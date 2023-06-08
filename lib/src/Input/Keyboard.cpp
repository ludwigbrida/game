#include <Engine/Input/Keyboard.hpp>
#include <iostream>

namespace ng::Keyboard {

void callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	keys[static_cast<Key>(key)] = action != GLFW_RELEASE;
}

void setup(GLFWwindow* window) {
	glfwSetKeyCallback(window, callback);
}

bool isKeyPressed(Key key) {
	return keys[key];
}

}
