#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../../systems/System.hpp"
#include "../Component.hpp"
#include "../Entity.hpp"
#include <concepts>
#include <memory>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <vector>

template <typename T>
concept SystemType = std::is_base_of_v<System, T>;

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
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
};

#endif
