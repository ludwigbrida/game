#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../types/composable.hpp"
#include "../types/systemic.hpp"
#include "component.hpp"
#include "entity.hpp"
#include "system.hpp"
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
	void setup();

	void update(float deltaTime);

	template <Composable T>
	void add(Entity entity, T value);

	template <Composable T>
	void remove(Entity entity);

	template <Composable T>
	bool has(Entity entity);

	template <Composable T>
	T& get(Entity entity);

	template <Systemic T>
	void activate();

	template <Systemic T>
	void deactivate();

	template <Composable... T>
	std::unordered_set<Entity> view();

private:
	std::unordered_map<std::type_index, ComponentMap> components;
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;

	template <Composable T>
	ComponentMap& getComponentMap();

	template <Composable... T>
	std::array<std::reference_wrapper<ComponentMap>, sizeof...(T)>
	getComponentMaps();
};

template <Composable T>
void Registry::add(Entity entity, T value) {
	std::unique_ptr<T> component = std::make_unique<T>(value);
	components[typeid(T)].insert({entity, std::move(component)});
}

template <Composable T>
void Registry::remove(Entity entity) {
	components[typeid(T)].erase(entity);
}

template <Composable T>
bool Registry::has(Entity entity) {
	return components[typeid(T)].count(entity);
}

template <Composable T>
T& Registry::get(Entity entity) {
	return dynamic_cast<T&>(*components[typeid(T)].at(entity));
}

template <Systemic T>
void Registry::activate() {
	std::unique_ptr<T> system = std::make_unique<T>();
	systems.insert({typeid(T), std::move(system)});
}

template <Systemic T>
void Registry::deactivate() {
	systems.erase(typeid(T));
}

template <Composable... T>
std::unordered_set<Entity> Registry::view() {
	std::unordered_set<Entity> iteratedEntities;
	std::unordered_set<Entity> filteredEntities;

	auto componentMaps = getComponentMaps<T...>();

	for (auto& [key, value] : componentMaps[0].get()) {
		iteratedEntities.insert(key);
		filteredEntities.insert(key);
	}

	for (auto entity : iteratedEntities) {
		for (auto& componentMap : componentMaps) {
			if (!componentMap.get().contains(entity)) {
				filteredEntities.erase(entity);
			}
		}
	}

	return filteredEntities;
}

template <Composable T>
ComponentMap& Registry::getComponentMap() {
	return components[typeid(T)];
}

// todo: how to properly store a collection of references?
template <Composable... T>
std::array<std::reference_wrapper<ComponentMap>, sizeof...(T)>
Registry::getComponentMaps() {
	return {std::ref(getComponentMap<T>())...};
}

#endif
