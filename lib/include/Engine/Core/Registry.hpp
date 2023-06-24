#ifndef ENGINE_REGISTRY_HPP
#define ENGINE_REGISTRY_HPP

#include "Component.hpp"
#include "Entity.hpp"
#include "State.hpp"
#include "System.hpp"
#include <Engine/Core/Clock.hpp>
#include <functional>
#include <initializer_list>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

namespace Engine {

using ComponentMap = std::unordered_map<Entity, std::unique_ptr<Component>>;

class Registry {
public:
	void setup();

	void run(State& state, const Clock& clock);

	template <IsComponent T, typename... Args>
	void addWithArgs(Entity entity, Args&&... args);

	template <IsComponent T>
	void add(Entity entity, T value = {});

	template <IsComponent T>
	void update(Entity entity, std::function<void(T&)> updateFunc) {
		if (!has<T>(entity)) {
			add<T>(entity);
		}

		auto& component = get<T>(entity);

		updateFunc(component);

		auto& baseComponent = static_cast<Component&>(component);
		baseComponent.isDirty = true;
	}

	template <IsComponent T>
	void remove(Entity entity);

	template <IsComponent T>
	bool has(Entity entity);

	template <IsComponent T>
	T& get(Entity entity);

	template <IsSystem T>
	void activate();

	template <IsSystem T>
	void activate(const T& system);

	template <IsSystem T>
	void deactivate();

	template <IsComponent... T>
	std::unordered_set<Entity> view();

private:
	std::unordered_map<std::type_index, ComponentMap> components;
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;

	template <IsComponent T>
	ComponentMap& getComponentMap();

	template <IsComponent... T>
	std::array<std::reference_wrapper<ComponentMap>, sizeof...(T)>
	getComponentMaps();
};

}

#include "Registry.inl"

#endif
