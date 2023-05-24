#ifndef GAME_ARITHMETIC_HPP
#define GAME_ARITHMETIC_HPP

#include <concepts>
#include <type_traits>

template <typename T>
concept Arithmetic = std::is_arithmetic<T>::value;

#endif
