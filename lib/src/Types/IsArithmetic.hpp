#ifndef ENGINE_IS_ARITHMETIC_HPP
#define ENGINE_IS_ARITHMETIC_HPP

#include <type_traits>

namespace ng {

template <typename T>
concept IsArithmetic = std::is_arithmetic<T>::value;

}

#endif
