#include "Quaternion.hpp"
#include <cmath>

namespace ng {

template <typename T>
Quaternion<T> Quaternion<T>::fromAxisAngle(const Vector<T>& axis,
                                           const T& angle) {
  const T sine = std::sin(angle / 2);
  const T cosine = std::cos(angle / 2);
  auto vector = axis * Vector<T>(sine, sine, sine);
  auto quaternion = Quaternion<T>();
  quaternion.x = vector.x;
  quaternion.y = vector.y;
  quaternion.z = vector.z;
  quaternion.w = cosine;
  return quaternion;
}

template class Quaternion<float>;
template class Quaternion<double>;

}
