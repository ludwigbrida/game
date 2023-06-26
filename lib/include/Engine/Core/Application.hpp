#ifndef ENGINE_APPLICATION_HPP
#define ENGINE_APPLICATION_HPP

#include <Engine/Core/Clock.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>
#include <Engine/Core/Types.hpp>
#include <Engine/Core/Window.hpp>

namespace Engine {

class Application {
public:
	Application();
	void run();

	Registry registry;

protected:
	Clock clock;
	Window window;
	State state;
};

}

#endif
