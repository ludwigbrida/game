#ifndef ENGINE_REGISTRY_INL
#define ENGINE_REGISTRY_INL

namespace ng {

template <IsComponent T>
void Registry::add(Entity entity, T value) {
	auto component = std::make_unique<T>(value);
	components[typeid(T)].insert({entity, std::move(component)});
	// TODO: evaluate idea
	// - There are multiple base classes of component (e.g. DirtyComponent)
	// - For components that inherit from DirtyComponent, the dirty state is
	//	 tracked in a separate map
}

template <IsComponent T>
void Registry::remove(Entity entity) {
	components[typeid(T)].erase(entity);
}

template <IsComponent T>
bool Registry::has(Entity entity) {
	return components[typeid(T)].count(entity);
}

template <IsComponent T>
T& Registry::get(Entity entity) {
	return static_cast<T&>(*components[typeid(T)].at(entity));
}

template <IsSystem T>
void Registry::activate() {
	auto system = std::make_unique<T>();
	systems.insert({typeid(T), std::move(system)});
}

template <IsSystem T>
void Registry::activate(T&& t) {
	auto system = std::make_unique<T>(t);
	systems.insert({typeid(T), std::move(system)});
}

template <IsSystem T>
void Registry::deactivate() {
	systems.erase(typeid(T));
}

// TODO: improve

template <IsComponent... T>
std::unordered_set<Entity> Registry::view() {
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
}

template <IsComponent T>
ComponentMap& Registry::getComponentMap() {
	return components[typeid(T)];
}

// todo: how to properly store a collection of references?
template <IsComponent... T>
std::array<std::reference_wrapper<ComponentMap>, sizeof...(T)> Registry::
	getComponentMaps() {
	return {std::ref(getComponentMap<T>())...};
}

}

#endif
