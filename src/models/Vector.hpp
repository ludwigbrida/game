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

  ~Vector() = default;
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

}

#endif
