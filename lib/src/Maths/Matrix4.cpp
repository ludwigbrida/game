#include <Engine/Maths/Matrix4.hpp>
#include <cmath>

namespace ng {

template <IsArithmetic T>
Matrix4<T>::Matrix4(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13,
										T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33)
		: m00{m00}, m01{m01}, m02{m02}, m03{m03}, m10{m10}, m11{m11}, m12{m12},
			m13{m13}, m20{m20}, m21{m21}, m22{m22}, m23{m23}, m30{m30}, m31{m31},
			m32{m32}, m33{m33} {}

template <IsArithmetic T>
Matrix4<T> Matrix4<T>::operator*(const Matrix4<T>& other) const {
	return {
		m00 * other.m00 + m01 * other.m10 + m02 * other.m20 + m03 * other.m30,
		m00 * other.m01 + m01 * other.m11 + m02 * other.m21 + m03 * other.m31,
		m00 * other.m02 + m01 * other.m12 + m02 * other.m22 + m03 * other.m32,
		m00 * other.m03 + m01 * other.m13 + m02 * other.m23 + m03 * other.m33,
		m10 * other.m00 + m11 * other.m10 + m12 * other.m20 + m13 * other.m30,
		m10 * other.m01 + m11 * other.m11 + m12 * other.m21 + m13 * other.m31,
		m10 * other.m02 + m11 * other.m12 + m12 * other.m22 + m13 * other.m32,
		m10 * other.m03 + m11 * other.m13 + m12 * other.m23 + m13 * other.m33,
		m20 * other.m00 + m21 * other.m10 + m22 * other.m20 + m23 * other.m30,
		m20 * other.m01 + m21 * other.m11 + m22 * other.m21 + m23 * other.m31,
		m20 * other.m02 + m21 * other.m12 + m22 * other.m22 + m23 * other.m32,
		m20 * other.m03 + m21 * other.m13 + m22 * other.m23 + m23 * other.m33,
		m30 * other.m00 + m31 * other.m10 + m32 * other.m20 + m33 * other.m30,
		m30 * other.m01 + m31 * other.m11 + m32 * other.m21 + m33 * other.m31,
		m30 * other.m02 + m31 * other.m12 + m32 * other.m22 + m33 * other.m32,
		m30 * other.m03 + m31 * other.m13 + m32 * other.m23 + m33 * other.m33,
	};
}

template <IsArithmetic T>
Matrix4<T> Matrix4<T>::fromPosition(const Vector3<T>& position) {
	auto matrix = Matrix4<T>::Identity;
	matrix.m30 = position.x;
	matrix.m31 = position.y;
	matrix.m32 = position.z;
	return matrix;
}

template <IsArithmetic T>
Matrix4<T> Matrix4<T>::fromScale(const Vector3<T>& scale) {
	auto matrix = Matrix4<T>::Identity;
	matrix.m00 = scale.x;
	matrix.m11 = scale.y;
	matrix.m22 = scale.z;
	return matrix;
}

template <IsArithmetic T>
Matrix4<T> Matrix4<T>::fromTransform(const Transform& transform) {
	const auto& position = Matrix4<T>::fromPosition(transform.position);
	// const auto& rotation = Matrix4<T>::fromRotation(transform.rotation);
	const auto& scale = Matrix4<T>::fromScale(transform.scale);
	return position * scale;
}

template <IsArithmetic T>
Matrix4<T> Matrix4<T>::fromPerspective(T fieldOfView, T aspectRatio, T near,
																			 T far) {
	const T fov = 1 / std::tan(fieldOfView / 2);
	const T inv = 1 / (near - far);

	auto matrix = Matrix4<T>::Identity;
	matrix.m00 = fov / aspectRatio;
	matrix.m11 = fov;
	matrix.m22 = (near + far) * inv;
	matrix.m23 = -1;
	matrix.m32 = near * far * inv * 2;
	return matrix;
}

template class Matrix4<Float>;

}
