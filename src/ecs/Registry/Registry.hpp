#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../components/Component.hpp"
#include "../../systems/System.hpp"
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <vector>

class Registry {
public:
	void run(float deltaTime);

	template <ComponentType T>
	void addComponent(int entity, const T& data);

	template <ComponentType T>
	void removeComponent(int entity);

	template <SystemType T>
	void addSystem();

	template <SystemType T>
	void removeSystem();

private:
	std::unordered_map<std::type_index,
										 std::unordered_map<int, std::unique_ptr<Component>>>
			components;
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
};

template <ComponentType T>
void Registry::addComponent(int entity, const T& data) {
	std::unique_ptr<T> component = std::make_unique<T>(data);
	components[std::type_index(typeid(T))].insert({entity, std::move(component)});
}

template <ComponentType T>
void Registry::removeComponent(int entity) {
	components[std::type_index(typeid(T))].erase(entity);
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

#endif
