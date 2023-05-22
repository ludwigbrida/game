#ifndef ENGINE_VECTOR3_HPP
#define ENGINE_VECTOR3_HPP

namespace ng {

template <typename T>
class Vector3 {
public:
	T x{};
	T y{};
	T z{};

	static const Vector3<T> Right;
};

using Vector3f = Vector3<float>;

}

#include <Engine/Maths/Vector3.inl>

#endif
