#ifndef GAME_VECTOR_HPP
#define GAME_VECTOR_HPP

namespace ng {

template <typename T>
struct Vector {
  T x;
  T y;
  T z;

  Vector();
  Vector(T x, T y, T z);

  T dot(const Vector<T>& vector) const;
  Vector<T> cross(const Vector<T>& vector) const;

  T length() const;

  static Vector<T> Right;
  static Vector<T> Left;
  static Vector<T> Up;
  static Vector<T> Down;
  static Vector<T> Backward;
  static Vector<T> Forward;
};

template <typename T>
Vector<T>& operator+=(Vector<T>& vector1, const Vector<T>& vector2);

template <typename T>
Vector<T>& operator-=(Vector<T>& vector1, const Vector<T>& vector2);

template <typename T>
Vector<T>& operator*=(Vector<T>& vector1, const Vector<T>& vector2);

template <typename T>
Vector<T>& operator/=(Vector<T>& vector1, const Vector<T>& vector2);

template <typename T>
Vector<T> operator+(const Vector<T>& vector1, const Vector<T>& vector2);

template <typename T>
Vector<T> operator-(const Vector<T>& vector1, const Vector<T>& vector2);

template <typename T>
Vector<T> operator*(const Vector<T>& vector1, const Vector<T>& vector2);

template <typename T>
Vector<T> operator/(const Vector<T>& vector1, const Vector<T>& vector2);

using Vector3f = Vector<float>;

}

#endif
