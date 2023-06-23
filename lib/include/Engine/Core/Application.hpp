#ifndef ENGINE_APPLICATION_HPP
#define ENGINE_APPLICATION_HPP

#include <Engine/Core/Clock.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>
#include <Engine/Core/Types.hpp>
#include <Engine/Core/Window.hpp>

namespace ng {

class Application {
public:
	Application(String name);
	void run();
	~Application();

private:
	Clock clock;

	Window window;
	Registry registry;
	State state;
};

}

#endif
