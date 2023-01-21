#include "Vector.hpp"

constexpr Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

constexpr Vector& operator+=(Vector& left, const Vector& right) {
  left.x += right.x;
  left.y += right.y;
  left.z += right.z;
  return left;
}
