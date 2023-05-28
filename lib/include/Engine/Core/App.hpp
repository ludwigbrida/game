#ifndef ENGINE_APP_HPP
#define ENGINE_APP_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/State.hpp>
#include <memory>

// TODO
class GLFWwindow;

namespace ng {

// TODO
class Registry;

class App {
public:
	App();
	void run();
	~App();

private:
	::GLFWwindow* window;

	std::unique_ptr<Registry> registry;
	State state;

	Int32 width = 960;
	Int32 height = 540;
};

}

#endif
