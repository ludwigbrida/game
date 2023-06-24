#include "Engine/Core/Registry.hpp"

namespace Engine {

void Registry::setup() {
	for (auto& [_, system]: systems) {
		system->setup();
	}
}

void Registry::run(State& state, const Clock& clock) {
	for (auto& [_, system]: systems) {
		system->update(*this, state, clock);
	}

	for (auto& [_, type]: components) {
		for (auto& [entity, component]: type) {
			component->isDirty = false;
		}
	}
}

}
