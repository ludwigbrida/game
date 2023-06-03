#ifndef GAME_QUATERNION_HPP
#define GAME_QUATERNION_HPP

#include <Engine/Core/Arithmetic.hpp>

namespace ng {

template <IsArithmetic T>
class Quaternion {
public:
	T x{};
	T y{};
	T z{};
	T w{1};
};

}

#endif
