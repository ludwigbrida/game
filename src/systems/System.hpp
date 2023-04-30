#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include "../components/TransformComponent.hpp"
#include <any>
#include <concepts>
#include <type_traits>
#include <typeindex>
#include <unordered_set>

template <ComponentType... Ts>
class System {
public:
	System();
	virtual void run(const float& deltaTime) = 0;
	virtual ~System() = default;

private:
	std::unordered_set<std::type_index> requirements;
};

template <ComponentType... Ts>
System<Ts...>::System() {
	requirements.insert({std::type_index(typeid(Ts))...});
}

template <typename T, typename... Args>
concept SystemType = std::is_base_of<System<Args...>, T>::value;

#endif
