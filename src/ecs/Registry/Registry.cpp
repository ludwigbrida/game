#include "Registry.hpp"
#include "../../systems/TransformSystem/TransformSystem.hpp"

template <SystemType T>
void Registry::run(float deltaTime) {
	for (auto& [_, system] : systems) {
		system->run(this, deltaTime);
	}

	removeSystem<TransformSystem>();
	addSystem<TransformSystem>();
}

template <SystemType T>
void Registry::addSystem() {
	std::unique_ptr<T> system = std::make_unique<T>();
	systems.insert({std::type_index(typeid(T)), system});
}

template <SystemType T>
void Registry::removeSystem() {
	systems.erase(std::type_index(typeid(T)));
}
