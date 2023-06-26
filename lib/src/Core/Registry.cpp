#include <Engine/Core/Registry.hpp>

namespace Engine {

void Registry::run(State& state, const Clock& clock) {
	for (const auto& [_, system]: systems) {
		system->run(*this, state, clock);
	}
}

}
