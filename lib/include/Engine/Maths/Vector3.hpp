#ifndef ENGINE_VECTOR3_HPP
#define ENGINE_VECTOR3_HPP

#include <Engine/Types/IsArithmetic.hpp>
#include <Engine/Types/Scalar.hpp>

namespace ng {

template <IsArithmetic T>
class Vector3 {
public:
	T x{};
	T y{};
	T z{};

	Vector3(T x, T y, T z);

	static const Vector3<T> Right;
	static const Vector3<T> Left;
	static const Vector3<T> Up;
	static const Vector3<T> Down;
	static const Vector3<T> Backward;
	static const Vector3<T> Forward;
};

template <IsArithmetic T>
const Vector3<T> Vector3<T>::Right{1, 0, 0};

using Vector3i = Vector3<Int32>;

using Vector3u = Vector3<UInt32>;

using Vector3f = Vector3<Float>;

}

#endif
