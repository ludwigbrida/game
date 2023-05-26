#ifndef ENGINE_MATRIX4_HPP
#define ENGINE_MATRIX4_HPP

#include <Engine/Types/IsArithmetic.hpp>
#include <Engine/Types/Scalar.hpp>

namespace ng {

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

	Matrix4(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21,
					T m22, T m23, T m30, T m31, T m32, T m33);

	Matrix4<T> operator*(const Matrix4<T>& other) const;
};

using Matrix4f = Matrix4<Float>;

}

#endif
