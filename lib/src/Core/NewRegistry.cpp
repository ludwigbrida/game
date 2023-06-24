#include <Engine/Core/NewRegistry.hpp>

namespace Engine {

void NewRegistry::run(State& state, const Clock& clock) {
	for (const auto& [_, system]: systems) {
		system->run(this, state, clock);
	}
}

}
