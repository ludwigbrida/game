#ifndef GAME_APP_HPP
#define GAME_APP_HPP

#include "../ecs/registry.hpp"
#include "../types_legacy/primitive.hpp"
#include "State.hpp"

class App {
public:
	App();
	void run();
	~App();

private:
	class GLFWwindow* window;

	Registry registry;
	State state;

	Int width = 960;
	Int height = 540;
};

#endif
