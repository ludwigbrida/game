#ifndef GAME_QUATERNION_HPP
#define GAME_QUATERNION_HPP

#include "../concepts/ArithmeticType.hpp"
#include "vector.hpp"

template <ArithmeticType T>
struct Quaternion {
	T x = 0;
	T y = 0;
	T z = 0;
	T w = 1;

	static Quaternion<T> fromAxisAngle(const Vector<T>& axis, T angle);
};

using Quaternion3f = Quaternion<float>;

using Quaternion3d = Quaternion<double>;

#endif
