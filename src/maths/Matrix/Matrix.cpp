#include "Matrix.hpp"
#include <cmath>

template <typename T>
Matrix<T>::Matrix() = default;

template <typename T>
Matrix<T>::Matrix(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20,
		  T m21, T m22, T m23, T m30, T m31, T m32, T m33)
    : m00(m00), m01(m01), m02(m02), m03(m03), m10(m10), m11(m11), m12(m12),
      m13(m13), m20(m20), m21(m21), m22(m22), m23(m23), m30(m30), m31(m31),
      m32(m32), m33(m33) {}

template <typename T>
Matrix<T> Matrix<T>::fromTranslation(const Vector<T>& vector) {
  auto matrix = Matrix<T>();
  matrix.m30 = vector.x;
  matrix.m31 = vector.y;
  matrix.m32 = vector.z;
  return matrix;
}

template <typename T>
Matrix<T> Matrix<T>::fromRotation(const Quaternion<T>& quaternion) {
  const T x2 = quaternion.x + quaternion.x;
  const T y2 = quaternion.y + quaternion.y;
  const T z2 = quaternion.z + quaternion.z;
  const T xx = quaternion.x * x2;
  const T yx = quaternion.y * x2;
  const T yy = quaternion.y * y2;
  const T zx = quaternion.z * x2;
  const T zy = quaternion.z * y2;
  const T zz = quaternion.z * z2;
  const T wx = quaternion.w * x2;
  const T wy = quaternion.w * y2;
  const T wz = quaternion.w * z2;
  auto matrix = Matrix<T>();
  matrix.m00 = 1 - yy - zz;
  matrix.m01 = yx - wz;
  matrix.m02 = zx - wy;
  matrix.m10 = yx - wz;
  matrix.m11 = 1 - xx - zz;
  matrix.m12 = zy + wx;
  matrix.m20 = zx + wy;
  matrix.m21 = zy - wx;
  matrix.m22 = 1 - xx - yy;
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

template <typename T>
Matrix<T> Matrix<T>::fromPerspective(const T& fieldOfView, const T& aspectRatio,
				     const T& near, const T& far) {
  const T fov = 1 / std::tan(fieldOfView / 2);
  const T inv = 1 / (near - far);

  auto matrix = Matrix<T>();
  matrix.m00 = fov / aspectRatio;
  matrix.m11 = fov;
  matrix.m22 = (near + far) * inv;
  matrix.m23 = -1;
  matrix.m32 = near * far * inv * 2;
  return matrix;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
  // todo
  return {};
}

template class Matrix<float>;

template class Matrix<double>;
