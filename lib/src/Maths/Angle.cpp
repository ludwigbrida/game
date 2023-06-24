#include <Engine/Maths/Angle.hpp>
#include <cmath>

namespace Engine {

template <IsArithmetic T>
Angle<T>::Angle(T degrees): degrees{degrees} {}

template <IsArithmetic T>
T Angle<T>::asDegrees() const {
	return degrees;
}

template <IsArithmetic T>
T Angle<T>::asRadians() const {
	return degrees * static_cast<T>(M_PI / 180);
}

Angle<Float> operator""_deg(UInt64 angle) {
	return {static_cast<Float>(angle)};
}

Angle<Float> operator""_deg(LDouble angle) {
	return {static_cast<Float>(angle)};
}

template class Angle<Float>;

}
