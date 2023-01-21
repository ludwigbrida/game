#include "Vector.hpp"

namespace ng {

template <typename T>
Vector<T>& operator+=(Vector<T>& vector1, const Vector<T>& vector2) {
  vector1.x += vector2.x;
  vector1.y += vector2.y;
  vector1.z += vector2.z;
  return vector1;
}

template <typename T>
Vector<T> operator+(const Vector<T>& vector1, const Vector<T>& vector2) {
  return {vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z};
}

}
