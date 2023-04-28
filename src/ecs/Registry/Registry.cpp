#include "Registry.hpp"

void Registry::run(float deltaTime) {
	for (auto& [_, system] : systems) {
		system->run(deltaTime);
	}
}

template <SystemType T>
void Registry::addSystem() {
	std::unique_ptr<T> system = std::make_unique<T>();
	systems.insert({std::type_index(typeid(T)), std::move(system)});
}

template <SystemType T>
void Registry::removeSystem() {
	systems.erase(std::type_index(typeid(T)));
}
