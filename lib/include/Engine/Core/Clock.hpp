#ifndef ENGINE_CLOCK_HPP
#define ENGINE_CLOCK_HPP

#include <Engine/Core/Arithmetic.hpp>

namespace Engine {

struct Clock {
	Float elapsedTime{};
	Float previousTime{};
	Float deltaTime{};
};

}

#endif
