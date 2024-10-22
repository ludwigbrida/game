#ifndef ENGINE_VECTOR3_INL
#define ENGINE_VECTOR3_INL

#include <cmath>

namespace Engine {

template <IsArithmetic T>
constexpr Vector3<T>::Vector3(): x{0}, y{0}, z{0} {}

template <IsArithmetic T>
constexpr Vector3<T>::Vector3(T x, T y, T z): x{x}, y{y}, z{z} {}

template <IsArithmetic T>
constexpr T Vector3<T>::length() const {
	return std::sqrt(dot(*this));
}

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::normalized() const {
	return (*this) / length();
}

template <IsArithmetic T>
constexpr T Vector3<T>::dot(const Vector3<T>& other) const {
	return x * other.x + y * other.y + z * other.z;
}

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::cross(const Vector3<T>& other) const {
	return {
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x,
	};
}

template <IsArithmetic T>
Vector3<T>::operator const T*() const {
	return reinterpret_cast<const T*>(this);
}

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
constexpr Vector3<T> Vector3<T>::operator*(T scalar) const {
	return {x * scalar, y * scalar, z * scalar};
}

template <IsArithmetic T>
constexpr Vector3<T> Vector3<T>::operator/(T scalar) const {
	return {x / scalar, y / scalar, z / scalar};
}

template <IsArithmetic T>
constexpr Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

template <IsArithmetic T>
constexpr Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

template <IsArithmetic T>
constexpr Vector3<T>& Vector3<T>::operator+=(T scalar) {
	x += scalar;
	y += scalar;
	z += scalar;
	return *this;
}

template <IsArithmetic T>
constexpr Vector3<T>& Vector3<T>::operator-=(T scalar) {
	x -= scalar;
	y -= scalar;
	z -= scalar;
	return *this;
}

template <IsArithmetic T>
constexpr Vector3<T>& Vector3<T>::operator*=(T scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

template <IsArithmetic T>
constexpr Vector3<T>& Vector3<T>::operator/=(T scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

template <IsArithmetic T>
constexpr bool Vector3<T>::operator==(const Vector3<T>& other) const {
	return (x == other.x) && (y == other.y) && (z == other.z);
}

template <IsArithmetic T>
constexpr bool Vector3<T>::operator!=(const Vector3<T>& other) const {
	return (x != other.x) || (y != other.y) || (z != other.z);
}

template <IsArithmetic T>
const Vector3<T> Vector3<T>::Zero{0, 0, 0};

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

}

#endif
