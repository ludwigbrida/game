#ifndef ENGINE_VECTOR3_HPP
#define ENGINE_VECTOR3_HPP

namespace ng {

template <typename T>
class Vector3 {
public:
	T x;
	T y;
	T z;

	constexpr Vector3();

	static const Vector3<T> right;
};

#include <Engine/maths/Vector3.inl>

using Vector3f = Vector3<float>;

}

#endif
