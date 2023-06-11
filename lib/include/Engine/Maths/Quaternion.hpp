#ifndef ENGINE_QUATERNION_HPP
#define ENGINE_QUATERNION_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Maths/Angle.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace ng {

template <IsArithmetic T>
class Quaternion {
public:
	T x{};
	T y{};
	T z{};
	T w{1};

	static Quaternion<T> fromAxisAngle(
		const Vector3<T>& axis,
		const Angle<T>& angle
	);
};

}

#endif
