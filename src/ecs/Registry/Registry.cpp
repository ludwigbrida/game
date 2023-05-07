#include "Registry.hpp"
#include "../System.hpp"

void Registry::run(float deltaTime) {
	for (auto& [_, system] : systems) {
		system->run(*this, deltaTime);
	}
}
