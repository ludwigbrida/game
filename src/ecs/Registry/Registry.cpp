#include "Registry.hpp"

void Registry::run(const float& deltaTime) {
	for (auto& system : systems) {
		system->run(this, deltaTime);
	}
}

void Registry::addSystem(const std::shared_ptr<System>& system) {
	this->systems.push_back(system);
}
