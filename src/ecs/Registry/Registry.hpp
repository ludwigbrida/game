#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../components/Component.hpp"
#include "../../concepts/ComponentType.hpp"
#include "../../concepts/SystemType.hpp"
#include "../../systems/System.hpp"
#include "../Entity.hpp"
#include <array>
#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ComponentMap = std::unordered_map<Entity, std::unique_ptr<Component>>;

class Registry {
public:
	void run(float deltaTime);

	template <ComponentType T>
	void addComponent(Entity entity);

	template <ComponentType T>
	void removeComponent(Entity entity);

	template <ComponentType T>
	bool hasComponent(Entity entity);

	template <ComponentType T>
	T& getComponent(Entity entity);

	template <SystemType T>
	void addSystem();

	template <SystemType T>
	void removeSystem();

	template <ComponentType... T>
	std::unordered_set<Entity> view();

private:
	std::unordered_map<std::type_index, ComponentMap> components;
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;

	template <ComponentType T>
	ComponentMap& getComponentMap();

	template <ComponentType... T>
	std::array<std::reference_wrapper<ComponentMap>, sizeof...(T)>
	getComponentMaps();
};

template <ComponentType T>
void Registry::addComponent(Entity entity) {
	std::unique_ptr<T> component = std::make_unique<T>();
	components[typeid(T)].insert({entity, std::move(component)});
}

template <ComponentType T>
void Registry::removeComponent(Entity entity) {
	components[typeid(T)].erase(entity);
}

template <ComponentType T>
bool Registry::hasComponent(Entity entity) {
	return components[typeid(T)].count(entity);
}

template <ComponentType T>
T& Registry::getComponent(Entity entity) {
	return dynamic_cast<T&>(*components[typeid(T)].at(entity));
}

template <SystemType T>
void Registry::addSystem() {
	std::unique_ptr<T> system = std::make_unique<T>();
	systems.insert({typeid(T), std::move(system)});
}

template <SystemType T>
void Registry::removeSystem() {
	systems.erase(typeid(T));
}

template <ComponentType... T>
std::unordered_set<Entity> Registry::view() {
	std::unordered_set<Entity> filteredEntities;

	auto componentMaps = getComponentMaps<T...>();

	for (auto& [key, value] : componentMaps[0].get()) {
		filteredEntities.insert(key);
	}

	for (auto entity : filteredEntities) {
		for (auto& componentMap : componentMaps) {
			if (!componentMap.get().contains(entity)) {
				filteredEntities.erase(entity);
			}
		}
	}

	// for (auto& componentMap : componentMaps) {
	//	for (auto& [key, _] : componentMap.get()) {
	//		if (!filteredEntities.contains(key)) {
	//			filteredEntities.erase(key); // todo: ???
	//		}
	//	}
	// }

	return filteredEntities;
}

template <ComponentType T>
ComponentMap& Registry::getComponentMap() {
	return components[typeid(T)];
}

// todo: how to properly store a collection of references?
template <ComponentType... T>
std::array<std::reference_wrapper<ComponentMap>, sizeof...(T)>
Registry::getComponentMaps() {
	return {std::ref(getComponentMap<T>())...};
}

#endif
