#include <Engine/maths/Vector3.hpp>

namespace ng {

template <typename T>
constexpr Vector3<T>::Vector3(T x, T y, T z) : x{x}, y{y}, z{z} {}

}
