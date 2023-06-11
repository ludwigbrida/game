#ifndef ENGINE_ANGLE_HPP
#define ENGINE_ANGLE_HPP

#include <Engine/Core/Arithmetic.hpp>

namespace ng {

template <IsArithmetic T>
class Angle {
public:
	Angle(T degrees);

	T asDegrees() const;

	T asRadians() const;

private:
	T degrees;
};

Angle<Float> operator""_deg(UInt64 angle);

Angle<Float> operator""_deg(LDouble angle);

}

#endif
