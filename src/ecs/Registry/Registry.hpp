#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../components/Component.hpp"
#include "../../systems/System.hpp"
#include "../Entity.hpp"
#include <concepts>
#include <memory>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <vector>

template <typename T>
concept SystemType = std::is_base_of<System, T>::value;

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
	std::unordered_map<std::type_index, std::shared_ptr<System>> systems;
};

template <SystemType T>
void Registry::addSystem() {
	std::shared_ptr<T> system = std::make_shared<T>();
	systems.insert({std::type_index(typeid(T)), system});
}

template <SystemType T>
void Registry::removeSystem() {
	systems.erase(std::type_index(typeid(T)));
}

#endif
