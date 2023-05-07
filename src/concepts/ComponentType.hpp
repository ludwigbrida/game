#ifndef GAME_COMPONENT_TYPE_HPP
#define GAME_COMPONENT_TYPE_HPP

#include "../ecs/Component.hpp"
#include <concepts>
#include <type_traits>

template <typename T>
concept ComponentType = std::is_base_of<Component, T>::value;

#endif
