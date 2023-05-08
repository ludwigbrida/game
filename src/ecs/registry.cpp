#include "registry.hpp"
#include "system.hpp"

void Registry::run(float deltaTime) {
	for (auto& [_, system] : systems) {
		system->run(*this, deltaTime);
	}
}
