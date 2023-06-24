#include <Engine/Maths/Quaternion.hpp>
#include <cmath>

namespace Engine {

template <IsArithmetic T>
Quaternion<T>::Quaternion(): x{0}, y{0}, z{0}, w{1} {}

template <IsArithmetic T>
Quaternion<T>::Quaternion(T x, T y, T z, T w): x{x}, y{y}, z{z}, w{w} {}

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
