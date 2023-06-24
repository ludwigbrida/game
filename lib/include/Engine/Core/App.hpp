#ifndef ENGINE_APP_HPP
#define ENGINE_APP_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Clock.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>

// TODO
class GLFWwindow;

namespace Engine {

class App {
public:
	App();
	void run();
	~App();

	Registry registry;
	State state;

private:
	::GLFWwindow* window;

	Clock clock;

	Int32 width = 1920;
	Int32 height = 1080;
};

}

#endif
