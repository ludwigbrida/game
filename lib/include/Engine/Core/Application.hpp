#ifndef ENGINE_APPLICATION_HPP
#define ENGINE_APPLICATION_HPP

#include <Engine/Core/Clock.hpp>
#include <Engine/Core/NewRegistry.hpp>
#include <Engine/Core/State.hpp>
#include <Engine/Core/Types.hpp>
#include <Engine/Core/Window.hpp>

namespace ng {

class Application {
public:
	Application();
	void run();

	NewRegistry registry;

private:
	Clock clock;
	Window window;
	State state;
};

}

#endif
