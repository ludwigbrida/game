#ifndef ENGINE_NEW_REGISTRY_HPP
#define ENGINE_NEW_REGISTRY_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Core/Entity.hpp>
#include <Engine/Core/System.hpp>
#include <memory>
#include <typeindex>
#include <unordered_map>

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
	T& get(Entity entity);

private:
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
	std::unordered_map<
		std::type_index,
		std::unordered_map<Entity, std::unique_ptr<Component>>>
		components;

	void run(State& state, const Clock& clock);
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
T& NewRegistry::get(Entity entity) {
	auto& component = *components[typeid(T)].at(entity);
	return static_cast<T&>(component);
}

}

#endif
