#ifndef GAME_COMPONENT_HPP
#define GAME_COMPONENT_HPP

#include <concepts>
#include <type_traits>

struct Component {};

template <typename T>
concept ComponentType = std::is_base_of<Component, T>::value;

#endif
