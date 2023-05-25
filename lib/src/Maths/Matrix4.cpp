#include <Engine/Maths/Matrix4.hpp>

namespace ng {

template <IsArithmetic T>
Matrix4<T>::Matrix4(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13,
										T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33)
		: m00{m00}, m01{m01}, m02{m02}, m03{m03}, m10{m10}, m11{m11}, m12{m12},
			m13{m13}, m20{m20}, m21{m21}, m22{m22}, m23{m23}, m30{m30}, m31{m31},
			m32{m32}, m33{m33} {}

template class Matrix4<Float>;

}
