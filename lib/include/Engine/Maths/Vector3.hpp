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

	constexpr Vector3(T x, T y, T z);

	constexpr Vector3<T> operator-() const;

	constexpr Vector3<T> operator+(const Vector3<T>& other) const;
	constexpr Vector3<T> operator-(const Vector3<T>& other) const;
	constexpr Vector3<T> operator*(const Vector3<T>& other) const;
	constexpr Vector3<T> operator/(const Vector3<T>& other) const;

	constexpr Vector3<T>& operator+=(const Vector3<T>& other);

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
