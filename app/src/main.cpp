#include "Systems/Movement.hpp"
#include <Engine/Core/App.hpp>

int main() {
	ng::App app;
	app.registry.activate<Movement>();
	app.run();
}
