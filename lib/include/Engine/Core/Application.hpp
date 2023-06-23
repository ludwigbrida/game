#ifndef ENGINE_APPLICATION_HPP
#define ENGINE_APPLICATION_HPP

#include <Engine/Core/Clock.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>

class GLFWwindow;

namespace ng {

class Application {
public:
	Application();
	void run();
	~Application();

private:
	::GLFWwindow* window;

	Int32 width = 1920;
	Int32 height = 1080;

	Clock clock;

	Registry registry;
	State state;
};

}

#endif
