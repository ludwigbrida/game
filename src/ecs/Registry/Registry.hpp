#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../components/Component.hpp"
#include "../../systems/System.hpp"
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>

class Registry {
public:
	void run(float deltaTime);

	template <SystemType T>
	void addSystem();

	template <SystemType T>
	void removeSystem();

private:
	std::vector<std::unordered_map<std::type_index, std::unique_ptr<Component>>>
			entities;
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
};

template <SystemType T>
void Registry::addSystem() {
	std::unique_ptr<T> system = std::make_unique<T>();
	systems.insert({std::type_index(typeid(T)), std::move(system)});
}

template <SystemType T>
void Registry::removeSystem() {
	systems.erase(std::type_index(typeid(T)));
}

#endif
