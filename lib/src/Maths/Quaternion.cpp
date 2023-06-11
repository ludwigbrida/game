#include <Engine/Maths/Quaternion.hpp>
#include <cmath>

namespace ng {

template <IsArithmetic T>
Quaternion<T> Quaternion<T>::fromAxisAngle(
	const Vector3<T>& axis,
	const Angle<T>& angle
) {
	const auto radians = angle.asRadians();
	const auto sine = std::sin(radians / 2);
	const auto cosine = std::cos(radians / 2);
	const auto vector = axis * sine;
	auto quaternion = Quaternion<T>();
	quaternion.x = vector.x;
	quaternion.y = vector.y;
	quaternion.z = vector.z;
	quaternion.w = cosine;
	return quaternion;
}

template class Quaternion<Float>;

}
