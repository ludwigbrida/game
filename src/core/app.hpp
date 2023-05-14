#ifndef GAME_APP_HPP
#define GAME_APP_HPP

#include "../ecs/registry.hpp"
#include "../types/primitive.hpp"

class App {
public:
	App();
	void run();
	~App();

private:
	class GLFWwindow* window;

	Registry registry;

	Int width = 640;
	Int height = 480;
};

#endif
