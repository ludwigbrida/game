#ifndef GAME_VECTOR_HPP
#define GAME_VECTOR_HPP

#include "../types/arithmetic.hpp"

template <Arithmetic T>
struct Vector {
	T x = 0;
	T y = 0;
	T z = 0;

	Vector();
	Vector(T x, T y, T z);

	T dot(const Vector<T>& vector) const;

	Vector<T> cross(const Vector<T>& vector) const;

	T length() const;

	Vector<T> normalized() const;

	static Vector<T> right;
	static Vector<T> left;
	static Vector<T> up;
	static Vector<T> down;
	static Vector<T> backward;
	static Vector<T> forward;
};

template <Arithmetic T>
Vector<T> Vector<T>::backward = Vector<T>(0, 0, 1);

template <Arithmetic T>
Vector<T>& operator+=(Vector<T>& vector1, const Vector<T>& vector2);

template <Arithmetic T>
Vector<T>& operator-=(Vector<T>& vector1, const Vector<T>& vector2);

template <Arithmetic T>
Vector<T>& operator*=(Vector<T>& vector1, const Vector<T>& vector2);

template <Arithmetic T>
Vector<T>& operator/=(Vector<T>& vector1, const Vector<T>& vector2);

template <Arithmetic T>
Vector<T> operator+(const Vector<T>& vector1, const Vector<T>& vector2);

template <Arithmetic T>
Vector<T> operator-(const Vector<T>& vector1, const Vector<T>& vector2);

template <Arithmetic T>
Vector<T> operator*(const Vector<T>& vector1, const Vector<T>& vector2);

template <Arithmetic T>
Vector<T> operator*(const Vector<T>& vector, T scalar) {
	return {vector.x * scalar, vector.y * scalar, vector.z * scalar};
}

template <Arithmetic T>
Vector<T> operator/(const Vector<T>& vector1, const Vector<T>& vector2);

using Vector3f = Vector<float>;

using Vector3d = Vector<double>;

#endif
