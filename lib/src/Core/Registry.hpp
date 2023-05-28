#ifndef ENGINE_REGISTRY_HPP
#define ENGINE_REGISTRY_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Core/Entity.hpp>
#include <Engine/Core/State.hpp>
#include <Engine/Core/System.hpp>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

namespace ng {

using ComponentMap = std::unordered_map<Entity, std::unique_ptr<Component>>;

class Registry {
public:
	void setup();

	void update(State& state, float deltaTime);

	template <IsComponent T>
	void add(Entity entity, T value = {});

	template <IsComponent T>
	void remove(Entity entity);

	template <IsComponent T>
	bool has(Entity entity);

	template <IsComponent T>
	T& get(Entity entity);

	template <IsSystem T>
	void activate();

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
