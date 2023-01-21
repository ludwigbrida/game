#include "Vector.hpp"

namespace ng {

template <typename T>
Vector<T>& operator+=(Vector<T>& left, const Vector<T>& right) {
  left.x += right.x;
  left.y += right.y;
  left.z += right.z;
  return left;
}

template <typename T>
Vector<T> operator+(const Vector<T>& left, const Vector<T>& right) {
  return {left.x + right.x, left.y + right.y, left.z + right.z};
}

}
