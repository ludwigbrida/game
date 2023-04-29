#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

#include <concepts>
#include <type_traits>

class System {
public:
	virtual void run(const float& deltaTime) = 0;
	virtual ~System() = default;
};

template <typename T>
concept SystemType = std::is_base_of<System, T>::value;

#endif
