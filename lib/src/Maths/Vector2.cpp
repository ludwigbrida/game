#include <Engine/Maths/Vector2.hpp>

namespace ng {

template <IsArithmetic T>
Vector2<T>::Vector2(): x{0}, y{0} {}

template <IsArithmetic T>
Vector2<T>::Vector2(T x, T y): x{x}, y{y} {}

template class Vector2<Float>;

}
