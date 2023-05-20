#ifndef GAME_SYSTEMIC_HPP
#define GAME_SYSTEMIC_HPP

#include "../ecs/system.hpp"
#include <concepts>
#include <type_traits>

template <typename T>
concept Systemic = std::is_base_of<System, T>::value;

#endif
