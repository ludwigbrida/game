#include "registry.hpp"
#include "system.hpp"

void Registry::setup() {
	for (auto& [_, system] : systems) {
		system->setup();
	}
}

void Registry::update(float deltaTime) {
	for (auto& [_, system] : systems) {
		system->update(*this, deltaTime);
	}
}
