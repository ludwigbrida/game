#ifndef GAME_MATRIX_HPP
#define GAME_MATRIX_HPP

#include "../Vector/Vector.hpp"

namespace ng {

template <typename T>
struct Matrix {
  T m00 = 1;
  T m01 = 0;
  T m02 = 0;
  T m03 = 0;
  T m10 = 0;
  T m11 = 1;
  T m12 = 0;
  T m13 = 0;
  T m20 = 0;
  T m21 = 0;
  T m22 = 1;
  T m23 = 0;
  T m30 = 0;
  T m31 = 0;
  T m32 = 0;
  T m33 = 1;

  static Matrix<T> fromTranslation(const Vector<T>& vector);
  static Matrix<T> fromScale(const Vector<T>& vector);
};

using Matrix4f = Matrix<float>;

}

#endif
