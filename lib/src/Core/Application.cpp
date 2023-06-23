#include <Engine/Core/Application.hpp>
#include <sstream>

namespace ng {

Application::Application(String name): window{1920, 1080, name} {}

void Application::run() {
	while (window.isOpen()) {
		clock.elapsedTime = static_cast<Float>(glfwGetTime());
		clock.deltaTime = clock.elapsedTime - clock.previousTime;
		clock.previousTime = clock.elapsedTime;

		std::stringstream title;
		title << "Game [" << static_cast<UInt32>(1 / clock.deltaTime) << " fps]";

		window.setTitle(title.str().c_str());

		window.pollEvents();

		registry.run(state, clock);

		window.swapBuffers();
	}
}

}
