#include <Engine/Maths/Vector3.hpp>

namespace ng {

template <IsArithmetic T>
Vector3<T>::Vector3(T x, T y, T z) : x{x}, y{y}, z{z} {}

template class Vector3<Int32>;

template class Vector3<UInt32>;

template class Vector3<Float>;

}
