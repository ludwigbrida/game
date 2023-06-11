#include <Engine/Maths/Vector2.hpp>

namespace ng {

template <IsArithmetic T>
Vector2<T>::Vector2(): x{0}, y{0} {}

template <IsArithmetic T>
Vector2<T>::Vector2(T x, T y): x{x}, y{y} {}

template <IsArithmetic T>
const Vector2<T> Vector2<T>::Zero{0, 0};

template class Vector2<Float>;

}
