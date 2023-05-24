#ifndef GAME_COMPOSABLE_HPP
#define GAME_COMPOSABLE_HPP

#include "../ecs/component.hpp"
#include <concepts>
#include <type_traits>

template <typename T>
concept Composable = std::is_base_of<Component, T>::value;

template <typename T>
concept Composable2 = std::is_trivial<T>::value && !std::is_scalar<T>::value;

#endif
