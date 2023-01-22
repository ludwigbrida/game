#include "Matrix.hpp"

namespace ng {

template <typename T>
Matrix<T> Matrix<T>::fromTranslation(const Vector<T>& vector) {
  auto matrix = Matrix<T>();
  matrix.m30 = vector.x;
  matrix.m31 = vector.y;
  matrix.m32 = vector.z;
  return matrix;
}

template <typename T>
Matrix<T> Matrix<T>::fromScale(const Vector<T>& vector) {
  auto matrix = Matrix<T>();
  matrix.m00 = vector.x;
  matrix.m11 = vector.y;
  matrix.m22 = vector.z;
  return matrix;
}

template class Matrix<float>;
template class Matrix<double>;
template class Matrix<long double>;

}
