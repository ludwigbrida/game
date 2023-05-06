#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../components/Component.hpp"
#include "../../concepts/ComponentType.hpp"
#include "../../concepts/SystemType.hpp"
#include "../../systems/System.hpp"
#include "../Entity.hpp"
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>

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
	std::vector<Entity> view() const;

private:
	std::unordered_map<std::type_index,
										 std::unordered_map<Entity, std::unique_ptr<Component>>>
			components;
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
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
std::vector<Entity> Registry::view() const {
	std::vector<Entity> filteredEntities;

	const std::type_index componentIndices[] = {typeid(T)...};

	for (const auto& componentIndex : componentIndices) {
		// components[componentIndex]
		// todo: collect entities that exist in all component arrays
	}

	return filteredEntities;
}

#endif
