#include "quaternion.hpp"
#include <cmath>

template <Arithmetic T>
Quaternion<T> Quaternion<T>::fromAxisAngle(const ng::Vector3<T>& axis,
																					 T angle) {
	/*const auto sine = std::sin(angle / 2);
	const auto cosine = std::cos(angle / 2);
	const auto vector = axis * sine;
	auto quaternion = Quaternion<T>();
	quaternion.x = vector.x;
	quaternion.y = vector.y;
	quaternion.z = vector.z;
	quaternion.w = cosine;
	return quaternion;*/
	return Quaternion<T>();
}

template class Quaternion<float>;

template class Quaternion<double>;