#ifndef GAME_APP_HPP
#define GAME_APP_HPP

#include "../ecs/registry.hpp"
#include "../types/primitive.hpp"
#include <GLFW/glfw3.h>

class App {
public:
	App();
	void run();
	~App();

private:
	GLFWwindow* window;

	Registry registry;

	Int width = 640;
	Int height = 480;
};

#endif
