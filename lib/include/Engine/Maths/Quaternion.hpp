#ifndef ENGINE_QUATERNION_HPP
#define ENGINE_QUATERNION_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Maths/Angle.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace Engine {

template <IsArithmetic T = Float>
class Quaternion {
public:
	T x;
	T y;
	T z;
	T w;

	Quaternion();
	Quaternion(T x, T y, T z, T w);

	static Quaternion<T> fromAxisAngle(
		const Vector3<T>& axis,
		const Angle<T>& angle
	);
};

}

#endif
