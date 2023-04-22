#include "Registry.hpp"

void Registry::addSystem(const std::shared_ptr<System>& system) {
	this->systems.push_back(system);
}
