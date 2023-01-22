#include "Vector.hpp"
#include <cmath>

namespace ng {

template <typename T>
Vector<T>::Vector() = default;

template <typename T>
Vector<T>::Vector(T x, T y, T z) : x(x), y(y), z(z) {}

template <typename T>
T Vector<T>::dot(const Vector<T>& vector) const {
  return x * vector.x + y * vector.y + z * vector.z;
}

template <typename T>
Vector<T> Vector<T>::cross(const Vector<T>& vector) const {
  return Vector<T>((y * vector.z) - (z * vector.y),
                   (z * vector.x) - (x * vector.z),
                   (x * vector.y) - (y * vector.x));
}

template <typename T>
T Vector<T>::length() const {
  return std::sqrt(dot(*this));
}

template <typename T>
Vector<T> Vector<T>::normalized() const {
  // todo: implement scalar division
  return (*this) / Vector<T>(length(), length(), length());
}

template <typename T>
Vector<T> Vector<T>::Right = Vector<T>(1, 0, 0);

template <typename T>
Vector<T> Vector<T>::Left = Vector<T>(-1, 0, 0);

template <typename T>
Vector<T> Vector<T>::Up = Vector<T>(0, 1, 0);

template <typename T>
Vector<T> Vector<T>::Down = Vector<T>(0, -1, 0);

template <typename T>
Vector<T> Vector<T>::Backward = Vector<T>(0, 0, 1);

template <typename T>
Vector<T> Vector<T>::Forward = Vector<T>(0, 0, -1);

template <typename T>
Vector<T>& operator+=(Vector<T>& vector1, const Vector<T>& vector2) {
  vector1.x += vector2.x;
  vector1.y += vector2.y;
  vector1.z += vector2.z;
  return vector1;
}

template <typename T>
Vector<T>& operator-=(Vector<T>& vector1, const Vector<T>& vector2) {
  vector1.x -= vector2.x;
  vector1.y -= vector2.y;
  vector1.z -= vector2.z;
  return vector1;
}

template <typename T>
Vector<T>& operator*=(Vector<T>& vector1, const Vector<T>& vector2) {
  vector1.x *= vector2.x;
  vector1.y *= vector2.y;
  vector1.z *= vector2.z;
  return vector1;
}

template <typename T>
Vector<T>& operator/=(Vector<T>& vector1, const Vector<T>& vector2) {
  vector1.x /= vector2.x;
  vector1.y /= vector2.y;
  vector1.z /= vector2.z;
  return vector1;
}

template <typename T>
Vector<T> operator+(const Vector<T>& vector1, const Vector<T>& vector2) {
  return {vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z};
}

template <typename T>
Vector<T> operator-(const Vector<T>& vector1, const Vector<T>& vector2) {
  return {vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z};
}

template <typename T>
Vector<T> operator*(const Vector<T>& vector1, const Vector<T>& vector2) {
  return {vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z};
}

template <typename T>
Vector<T> operator/(const Vector<T>& vector1, const Vector<T>& vector2) {
  return {vector1.x / vector2.x, vector1.y / vector2.y, vector1.z / vector2.z};
}

template class Vector<float>;
template class Vector<double>;
template class Vector<long double>;

}
