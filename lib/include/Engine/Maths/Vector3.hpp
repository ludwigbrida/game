#ifndef ENGINE_VECTOR3_HPP
#define ENGINE_VECTOR3_HPP

#include <Engine/Core/Arithmetic.hpp>

namespace Engine {

template <IsArithmetic T>
class Vector3 {
public:
	T x;
	T y;
	T z;

	constexpr Vector3();
	constexpr Vector3(T x, T y, T z);

	constexpr T length() const;
	constexpr Vector3<T> normalized() const;

	constexpr T dot(const Vector3<T>& other) const;
	constexpr Vector3<T> cross(const Vector3<T>& other) const;

	operator const T*() const; // NOLINT

	constexpr Vector3<T> operator-() const;

	constexpr Vector3<T> operator+(const Vector3<T>& other) const;
	constexpr Vector3<T> operator-(const Vector3<T>& other) const;
	constexpr Vector3<T> operator*(const Vector3<T>& other) const;
	constexpr Vector3<T> operator/(const Vector3<T>& other) const;
	constexpr Vector3<T> operator*(T scalar) const;
	constexpr Vector3<T> operator/(T scalar) const;

	constexpr Vector3<T>& operator+=(const Vector3<T>& other);
	constexpr Vector3<T>& operator-=(const Vector3<T>& other);
	constexpr Vector3<T>& operator+=(T scalar);
	constexpr Vector3<T>& operator-=(T scalar);
	constexpr Vector3<T>& operator*=(T scalar);
	constexpr Vector3<T>& operator/=(T scalar);

	constexpr bool operator==(const Vector3<T>& other) const;
	constexpr bool operator!=(const Vector3<T>& other) const;

	static const Vector3<T> Zero;
	static const Vector3<T> Right;
	static const Vector3<T> Left;
	static const Vector3<T> Up;
	static const Vector3<T> Down;
	static const Vector3<T> Backward;
	static const Vector3<T> Forward;
};

}

#include <Engine/Maths/Vector3.inl>

#endif
