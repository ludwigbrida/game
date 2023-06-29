#ifndef ENGINE_KEYBOARD_HPP
#define ENGINE_KEYBOARD_HPP

#include <GLFW/glfw3.h>
#include <unordered_map>

namespace Engine::Keyboard {

enum struct Key {
	W = 87,
	A = 65,
	S = 83,
	D = 68
};

void setup(GLFWwindow* window);

bool isKeyPressed(Key key);

static std::unordered_map<Key, bool> keys;

}

#endif
