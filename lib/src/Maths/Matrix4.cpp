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
Matrix4<T>::operator const T*() const {
	return reinterpret_cast<const T*>(this);
}

template <IsArithmetic T>
Matrix4<T> Matrix4<T>::inverted() const {
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
Matrix4<T> Matrix4<T>::fromPerspective(const Perspective& perspective) {
	const T fov = 1 / std::tan(perspective.fieldOfView / 2);
	const T inv = 1 / (perspective.near - perspective.far);

	auto matrix = Matrix4<T>::Identity;
	matrix.m00 = fov / perspective.aspectRatio;
	matrix.m11 = fov;
	matrix.m22 = (perspective.near + perspective.far) * inv;
	matrix.m23 = -1;
	matrix.m32 = perspective.near * perspective.far * inv * 2;
	return matrix;
}

template class Matrix4<Float>;

}
