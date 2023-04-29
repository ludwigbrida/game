#include "Registry.hpp"

void Registry::run(float deltaTime) {
	for (auto& [_, system] : systems) {
		system->run(deltaTime);
	}
}
