#ifndef ENGINE_MATRIX4_HPP
#define ENGINE_MATRIX4_HPP

#include <Engine/Components/Camera.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Arithmetic.hpp>

namespace Engine {

template <IsArithmetic T>
class Matrix4 {
public:
	T m00{1};
	T m01{};
	T m02{};
	T m03{};
	T m10{};
	T m11{1};
	T m12{};
	T m13{};
	T m20{};
	T m21{};
	T m22{1};
	T m23{};
	T m30{};
	T m31{};
	T m32{};
	T m33{1};

	Matrix4();
	Matrix4(
		T m00,
		T m01,
		T m02,
		T m03,
		T m10,
		T m11,
		T m12,
		T m13,
		T m20,
		T m21,
		T m22,
		T m23,
		T m30,
		T m31,
		T m32,
		T m33
	);

	Matrix4<T> operator*(const Matrix4<T>& other) const;

	Vector3<T> operator*(const Vector3<T>& vector) const;

	operator const T*() const; // NOLINT

	Matrix4<T> inverted() const;

	static Matrix4<T> fromPosition(const Vector3<T>& position);
	static Matrix4<T> fromRotation(const Quaternion<T>& rotation);
	static Matrix4<T> fromScale(const Vector3<T>& scale);

	static Matrix4<T> fromTransform(const Transform& transform);

	static Matrix4<T> fromPerspective(const Camera& perspective);

	static const Matrix4<T> Identity;
};

template <IsArithmetic T>
const Matrix4<T> Matrix4<T>::Identity{
	1,
	0,
	0,
	0,
	0,
	1,
	0,
	0,
	0,
	0,
	1,
	0,
	0,
	0,
	0,
	1,
};

}

#endif
