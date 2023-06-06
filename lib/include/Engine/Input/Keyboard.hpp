#ifndef ENGINE_KEYBOARD_HPP
#define ENGINE_KEYBOARD_HPP

#include <GLFW/glfw3.h>
#include <unordered_map>

namespace ng {

class Keyboard {
public:
	explicit Keyboard(GLFWwindow* window);

	bool isKeyDown(int key);

private:
	static void callback(GLFWwindow* window, int key, int scancode, int action,
											 int mods);

	static std::unordered_map<int, bool> keys;
};

}

#endif
