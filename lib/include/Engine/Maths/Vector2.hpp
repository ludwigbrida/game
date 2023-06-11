#ifndef ENGINE_VECTOR2_HPP
#define ENGINE_VECTOR2_HPP

#include <Engine/Core/Arithmetic.hpp>

namespace ng {

template <IsArithmetic T>
class Vector2 {
public:
	T x;
	T y;

	Vector2();
	Vector2(T x, T y);

	static const Vector2<T> Zero;
};

}

#endif
