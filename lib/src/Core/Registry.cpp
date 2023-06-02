#include "Engine/Core/Registry.hpp"

namespace ng {

void Registry::setup() {
	for (auto& [_, system] : systems) {
		system->setup();
	}
}

void Registry::run(State& state, float deltaTime) {
	for (auto& [_, system] : systems) {
		system->update(*this, state, deltaTime);
	}

	for (auto& [_, type] : components) {
		for (auto& [entity, component] : type) {
			component->isDirty = false;
		}
	}
}

}
