#include "matrix.hpp"
#include <cmath>

template <Arithmetic T>
Matrix<T>::Matrix() = default;

template <Arithmetic T>
Matrix<T>::Matrix(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20,
									T m21, T m22, T m23, T m30, T m31, T m32, T m33)
		: m00(m00), m01(m01), m02(m02), m03(m03), m10(m10), m11(m11), m12(m12),
			m13(m13), m20(m20), m21(m21), m22(m22), m23(m23), m30(m30), m31(m31),
			m32(m32), m33(m33) {}

template <Arithmetic T>
Matrix<T> Matrix<T>::inverted() const {
	auto b00 = m00 * m11 - m01 * m10;
	auto b01 = m00 * m12 - m02 * m10;
	auto b02 = m00 * m13 - m03 * m10;
	auto b03 = m01 * m12 - m02 * m11;
	auto b04 = m01 * m13 - m03 * m11;
	auto b05 = m02 * m13 - m03 * m12;
	auto b06 = m20 * m31 - m21 * m30;
	auto b07 = m20 * m32 - m22 * m30;
	auto b08 = m20 * m33 - m23 * m30;
	auto b09 = m21 * m32 - m22 * m31;
	auto b10 = m21 * m33 - m23 * m31;
	auto b11 = m22 * m33 - m23 * m32;

	auto det =
		b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;

	det = 1 / det;

	return {
		(m11 * b11 - m12 * b10 + m13 * b09) * det,
		(m02 * b10 - m01 * b11 - m03 * b09) * det,
		(m31 * b05 - m32 * b04 + m33 * b03) * det,
		(m22 * b04 - m21 * b05 - m23 * b03) * det,
		(m12 * b08 - m10 * b11 - m13 * b07) * det,
		(m00 * b11 - m02 * b08 + m03 * b07) * det,
		(m32 * b02 - m30 * b05 - m33 * b01) * det,
		(m20 * b05 - m22 * b02 + m23 * b01) * det,
		(m10 * b10 - m11 * b08 + m13 * b06) * det,
		(m01 * b08 - m00 * b10 - m03 * b06) * det,
		(m30 * b04 - m31 * b02 + m33 * b00) * det,
		(m21 * b02 - m20 * b04 - m23 * b00) * det,
		(m11 * b07 - m10 * b09 - m12 * b06) * det,
		(m00 * b09 - m01 * b07 + m02 * b06) * det,
		(m31 * b01 - m30 * b03 - m32 * b00) * det,
		(m20 * b03 - m21 * b01 + m22 * b00) * det,
	};
}

template <Arithmetic T>
Matrix<T> Matrix<T>::fromTranslation(const Vector<T>& vector) {
	auto matrix = Matrix<T>();
	matrix.m30 = vector.x;
	matrix.m31 = vector.y;
	matrix.m32 = vector.z;
	return matrix;
}

template <Arithmetic T>
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

template <Arithmetic T>
Matrix<T> Matrix<T>::fromScale(const Vector<T>& vector) {
	auto matrix = Matrix<T>();
	matrix.m00 = vector.x;
	matrix.m11 = vector.y;
	matrix.m22 = vector.z;
	return matrix;
}

template <>
Matrix<float> Matrix<float>::fromTransform(const Transform& transform) {
	const auto translationMatrix = fromTranslation(transform.position);
	const auto rotationMatrix = fromRotation(transform.rotation);
	const auto scaleMatrix = fromScale(transform.scale);
	return translationMatrix * rotationMatrix * scaleMatrix;
}

template <Arithmetic T>
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

template <Arithmetic T>
Matrix<T> operator*(const Matrix<T>& matrix1, const Matrix<T>& matrix2) {
	return {
		matrix1.m00 * matrix2.m00 + matrix1.m01 * matrix2.m10 +
			matrix1.m02 * matrix2.m20 + matrix1.m03 * matrix2.m30,
		matrix1.m00 * matrix2.m01 + matrix1.m01 * matrix2.m11 +
			matrix1.m02 * matrix2.m21 + matrix1.m03 * matrix2.m31,
		matrix1.m00 * matrix2.m02 + matrix1.m01 * matrix2.m12 +
			matrix1.m02 * matrix2.m22 + matrix1.m03 * matrix2.m32,
		matrix1.m00 * matrix2.m03 + matrix1.m01 * matrix2.m13 +
			matrix1.m02 * matrix2.m23 + matrix1.m03 * matrix2.m33,
		matrix1.m10 * matrix2.m00 + matrix1.m11 * matrix2.m10 +
			matrix1.m12 * matrix2.m20 + matrix1.m13 * matrix2.m30,
		matrix1.m10 * matrix2.m01 + matrix1.m11 * matrix2.m11 +
			matrix1.m12 * matrix2.m21 + matrix1.m13 * matrix2.m31,
		matrix1.m10 * matrix2.m02 + matrix1.m11 * matrix2.m12 +
			matrix1.m12 * matrix2.m22 + matrix1.m13 * matrix2.m32,
		matrix1.m10 * matrix2.m03 + matrix1.m11 * matrix2.m13 +
			matrix1.m12 * matrix2.m23 + matrix1.m13 * matrix2.m33,
		matrix1.m20 * matrix2.m00 + matrix1.m21 * matrix2.m10 +
			matrix1.m22 * matrix2.m20 + matrix1.m23 * matrix2.m30,
		matrix1.m20 * matrix2.m01 + matrix1.m21 * matrix2.m11 +
			matrix1.m22 * matrix2.m21 + matrix1.m23 * matrix2.m31,
		matrix1.m20 * matrix2.m02 + matrix1.m21 * matrix2.m12 +
			matrix1.m22 * matrix2.m22 + matrix1.m23 * matrix2.m32,
		matrix1.m20 * matrix2.m03 + matrix1.m21 * matrix2.m13 +
			matrix1.m22 * matrix2.m23 + matrix1.m23 * matrix2.m33,
		matrix1.m30 * matrix2.m00 + matrix1.m31 * matrix2.m10 +
			matrix1.m32 * matrix2.m20 + matrix1.m33 * matrix2.m30,
		matrix1.m30 * matrix2.m01 + matrix1.m31 * matrix2.m11 +
			matrix1.m32 * matrix2.m21 + matrix1.m33 * matrix2.m31,
		matrix1.m30 * matrix2.m02 + matrix1.m31 * matrix2.m12 +
			matrix1.m32 * matrix2.m22 + matrix1.m33 * matrix2.m32,
		matrix1.m30 * matrix2.m03 + matrix1.m31 * matrix2.m13 +
			matrix1.m32 * matrix2.m23 + matrix1.m33 * matrix2.m33,
	};
}

template class Matrix<float>;

template class Matrix<double>;
