#ifndef GAME_QUATERNION_HPP
#define GAME_QUATERNION_HPP

#include "../Vector/Vector.hpp"

namespace ng {

template <typename T>
struct Quaternion {
  T x = 0;
  T y = 0;
  T z = 0;
  T w = 1;

  static Quaternion<T> fromAxisAngle(const Vector<T>& axis, const T& angle);
};

}

#endif
