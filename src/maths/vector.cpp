#include "vector.hpp"
#include <cmath>

template <ArithmeticType T>
Vector<T>::Vector() = default;

template <ArithmeticType T>
Vector<T>::Vector(T x, T y, T z) : x(x), y(y), z(z) {}

template <ArithmeticType T>
T Vector<T>::dot(const Vector<T>& vector) const {
	return x * vector.x + y * vector.y + z * vector.z;
}

template <ArithmeticType T>
Vector<T> Vector<T>::cross(const Vector<T>& vector) const {
	return Vector<T>((y * vector.z) - (z * vector.y),
									 (z * vector.x) - (x * vector.z),
									 (x * vector.y) - (y * vector.x));
}

template <ArithmeticType T>
T Vector<T>::length() const {
	return std::sqrt(dot(*this));
}

template <ArithmeticType T>
Vector<T> Vector<T>::normalized() const {
	// todo: implement scalar division
	return (*this) / Vector<T>(length(), length(), length());
}

template <ArithmeticType T>
Vector<T> Vector<T>::right = Vector<T>(1, 0, 0);

template <ArithmeticType T>
Vector<T> Vector<T>::left = Vector<T>(-1, 0, 0);

template <ArithmeticType T>
Vector<T> Vector<T>::up = Vector<T>(0, 1, 0);

template <ArithmeticType T>
Vector<T> Vector<T>::down = Vector<T>(0, -1, 0);

template <ArithmeticType T>
Vector<T> Vector<T>::forward = Vector<T>(0, 0, -1);

template <ArithmeticType T>
Vector<T>& operator+=(Vector<T>& vector1, const Vector<T>& vector2) {
	vector1.x += vector2.x;
	vector1.y += vector2.y;
	vector1.z += vector2.z;
	return vector1;
}

template <ArithmeticType T>
Vector<T>& operator-=(Vector<T>& vector1, const Vector<T>& vector2) {
	vector1.x -= vector2.x;
	vector1.y -= vector2.y;
	vector1.z -= vector2.z;
	return vector1;
}

template <ArithmeticType T>
Vector<T>& operator*=(Vector<T>& vector1, const Vector<T>& vector2) {
	vector1.x *= vector2.x;
	vector1.y *= vector2.y;
	vector1.z *= vector2.z;
	return vector1;
}

template <ArithmeticType T>
Vector<T>& operator/=(Vector<T>& vector1, const Vector<T>& vector2) {
	vector1.x /= vector2.x;
	vector1.y /= vector2.y;
	vector1.z /= vector2.z;
	return vector1;
}

template <ArithmeticType T>
Vector<T> operator+(const Vector<T>& vector1, const Vector<T>& vector2) {
	return {vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z};
}

template <ArithmeticType T>
Vector<T> operator-(const Vector<T>& vector1, const Vector<T>& vector2) {
	return {vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z};
}

template <ArithmeticType T>
Vector<T> operator*(const Vector<T>& vector1, const Vector<T>& vector2) {
	return {vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z};
}

template <ArithmeticType T>
Vector<T> operator/(const Vector<T>& vector1, const Vector<T>& vector2) {
	return {vector1.x / vector2.x, vector1.y / vector2.y, vector1.z / vector2.z};
}

template class Vector<float>;

template class Vector<double>;