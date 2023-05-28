#include "Engine/Core/Registry.hpp"

namespace ng {

void Registry::setup() {
	for (auto& [_, system] : systems) {
		system->setup();
	}
}

void Registry::update(State& state, float deltaTime) {
	for (auto& [_, system] : systems) {
		system->update(*this, state, deltaTime);
	}
}

}
