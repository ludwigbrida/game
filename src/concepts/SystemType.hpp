#ifndef GAME_SYSTEM_TYPE_HPP
#define GAME_SYSTEM_TYPE_HPP

#include "../systems/System.hpp"
#include <concepts>
#include <type_traits>

template <typename T>
concept SystemType = std::is_base_of<System, T>::value;

#endif