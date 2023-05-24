#ifndef GAME_MATRIX_HPP
#define GAME_MATRIX_HPP

#include "../components/Transform.hpp"
#include "../types_legacy/arithmetic.hpp"
#include "quaternion.hpp"
#include "vector.hpp"

template <Arithmetic T>
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

	Matrix();
	Matrix(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21,
				 T m22, T m23, T m30, T m31, T m32, T m33);

	Matrix<T> inverted() const;

	operator const T*() const { return reinterpret_cast<const T*>(this); }

	static Matrix<T> fromTranslation(const Vector<T>& vector);
	static Matrix<T> fromRotation(const Quaternion<T>& quaternion);
	static Matrix<T> fromScale(const Vector<T>& vector);

	static Matrix<float> fromTransform(const Transform& transform);

	static Matrix<T> fromPerspective(const T& fieldOfView, const T& aspectRatio,
																	 const T& near, const T& far);
};

template <Arithmetic T>
Matrix<T> operator*(const Matrix<T>& matrix1, const Matrix<T>& matrix2);

using Matrix4f = Matrix<float>;

using Matrix4d = Matrix<double>;

#endif
