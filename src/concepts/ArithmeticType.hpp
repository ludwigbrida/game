#ifndef GAME_ARITHMETIC_TYPE_HPP
#define GAME_ARITHMETIC_TYPE_HPP

#include <concepts>
#include <type_traits>

template <typename T>
concept ArithmeticType = std::is_arithmetic<T>::value;

#endif
