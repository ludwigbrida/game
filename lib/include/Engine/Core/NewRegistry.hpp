#ifndef ENGINE_NEW_REGISTRY_HPP
#define ENGINE_NEW_REGISTRY_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Core/Entity.hpp>
#include <Engine/Core/System.hpp>
#include <iostream>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

namespace Engine {

class NewRegistry {
public:
	template <IsSystem T, typename... Args>
	void activate(Args&&... args);

	template <IsSystem T>
	void deactivate();

	template <IsComponent T>
	void add(Entity entity, T component);

	template <IsComponent T>
	void remove(Entity entity);

	template <IsComponent T>
	bool has(Entity entity);

	template <IsComponent T>
	T& get(Entity entity);

	template <IsComponent... T>
	std::unordered_set<Entity> view();

private:
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
	std::unordered_map<
		std::type_index,
		std::unordered_map<Entity, std::unique_ptr<Component>>>
		components;

	void run(State& state, const Clock& clock);

	template <IsComponent... T>
	std::array<
		std::reference_wrapper<
			std::unordered_map<Entity, std::unique_ptr<Component>>>,
		sizeof...(T)>
	getComponentMaps();

	friend class Application;
};

template <IsSystem T, typename... Args>
void NewRegistry::activate(Args&&... args) {
	auto system = std::make_unique<T>(args...);
	systems.insert({typeid(T), std::move(system)});
}

template <IsSystem T>
void NewRegistry::deactivate() {
	systems.erase(typeid(T));
}

template <IsComponent T>
void NewRegistry::add(Entity entity, T component) {
	auto componentPtr = std::make_unique<T>(component);
	components[typeid(T)].insert({entity, std::move(componentPtr)});
}

template <IsComponent T>
void NewRegistry::remove(Entity entity) {
	components[typeid(T)].erase(entity);
}

template <IsComponent T>
bool NewRegistry::has(Entity entity) {
	return components[typeid(T)].count(entity);
}

template <IsComponent T>
T& NewRegistry::get(Entity entity) {
	auto& component = *components[typeid(T)].at(entity);
	return static_cast<T&>(component);
}

template <IsComponent... T>
std::unordered_set<Entity> NewRegistry::view() {
	std::unordered_set<Entity> iteratedEntities;
	std::unordered_set<Entity> filteredEntities;

	auto componentMaps = getComponentMaps<T...>();

	for (auto& [key, value]: componentMaps[0].get()) {
		iteratedEntities.insert(key);
		filteredEntities.insert(key);
	}

	for (auto entity: iteratedEntities) {
		for (auto& componentMap: componentMaps) {
			if (!componentMap.get().contains(entity)) {
				filteredEntities.erase(entity);
			}
		}
	}

	return filteredEntities;
	/* TODO: Alternative approach
	std::unordered_set<Entity> filteredEntities;

	auto componentMaps = getComponentMaps<T...>();

	unsigned int i = 0;
	for (auto& componentMap: componentMaps) {
		for (auto& [entity, component]: componentMap.get()) {
			if (i == 0) {
				std::cout << "insert: " << entity << std::endl;
				filteredEntities.insert(entity);
			} else {
				// TODO: should erase components that were NOT ALSO present in the first
				// TODO: component array
				std::cout << "erase: " << entity << std::endl;
				filteredEntities.erase(entity);
			}
		}
		i++;
	}

	return filteredEntities;*/
}

template <IsComponent... T>
std::array<
	std::reference_wrapper<
		std::unordered_map<Entity, std::unique_ptr<Component>>>,
	sizeof...(T)>
NewRegistry::getComponentMaps() {
	return {std::ref(components[typeid(T)])...};
}

}

#endif
