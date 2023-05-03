#include "Registry.hpp"
#include "../../systems/System.hpp"

void Registry::run(float deltaTime) {
	for (auto& [_, system] : systems) {
		system->run(*this, deltaTime);
	}
}
