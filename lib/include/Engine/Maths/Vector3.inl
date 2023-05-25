#ifndef ENGINE_VECTOR3_INL
#define ENGINE_VECTOR3_INL

#include <Engine/Types/Scalar.hpp>

namespace ng {

template <IsArithmetic T>
constexpr Vector3<T>::Vector3(T x, T y, T z) : x{x}, y{y}, z{z} {}

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::operator-() const {
	return {-x, -y, -z};
}

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) const {
	return {x + other.x, y + other.y, z + other.z};
}

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) const {
	return {x - other.x, y - other.y, z - other.z};
}

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::operator*(const Vector3<T>& other) const {
	return {x * other.x, y * other.y, z * other.z};
}

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::operator/(const Vector3<T>& other) const {
	return {x / other.x, y / other.y, z / other.z};
}

template <IsArithmetic T>
const Vector3<T> Vector3<T>::Right{1, 0, 0};

template <IsArithmetic T>
const Vector3<T> Vector3<T>::Left{-1, 0, 0};

template <IsArithmetic T>
const Vector3<T> Vector3<T>::Up{0, 1, 0};

template <IsArithmetic T>
const Vector3<T> Vector3<T>::Down{0, -1, 0};

template <IsArithmetic T>
const Vector3<T> Vector3<T>::Backward{0, 0, 1};

template <IsArithmetic T>
const Vector3<T> Vector3<T>::Forward{0, 0, -1};

using Vector3i = Vector3<Int32>;

using Vector3f = Vector3<Float>;

}

#endif
