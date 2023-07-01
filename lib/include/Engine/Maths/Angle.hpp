#ifndef ENGINE_ANGLE_HPP
#define ENGINE_ANGLE_HPP

#include <Engine/Core/Arithmetic.hpp>

namespace Engine {

template <IsArithmetic T>
class Angle {
public:
	Angle(T degrees);

	T asDegrees() const;

	T asRadians() const;

	Angle<T>& operator+=(T scalar);

	bool operator>(const Angle<T>& angle);
	bool operator>=(const Angle<T>& angle);
	bool operator<(const Angle<T>& angle);
	bool operator<=(const Angle<T>& angle);

private:
	T degrees;
};

template <IsArithmetic T>
Angle<T>& Angle<T>::operator+=(T scalar) {
	degrees += scalar;
	return *this;
}

template <IsArithmetic T>
bool Angle<T>::operator>(const Angle<T>& angle) {
	return degrees > angle.degrees;
}

template <IsArithmetic T>
bool Angle<T>::operator>=(const Angle<T>& angle) {
	return degrees >= angle.degrees;
}

template <IsArithmetic T>
bool Angle<T>::operator<(const Angle<T>& angle) {
	return degrees < angle.degrees;
}

template <IsArithmetic T>
bool Angle<T>::operator<=(const Angle<T>& angle) {
	return degrees <= angle.degrees;
}

Angle<Float> operator""_deg(UInt64 angle);

Angle<Float> operator""_deg(LDouble angle);

}

#endif
