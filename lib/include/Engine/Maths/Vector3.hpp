#ifndef ENGINE_VECTOR3_HPP
#define ENGINE_VECTOR3_HPP

#include <Engine/Types/IsArithmetic.hpp>

namespace ng {

template <IsArithmetic T>
class Vector3 {
public:
	T x{};
	T y{};
	T z{};

	static const Vector3<T> Right;
};

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::Right{1, 0, 0};

using Vector3f = Vector3<float>;

}

#endif
