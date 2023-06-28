#ifndef GAME_SPIN_HPP
#define GAME_SPIN_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Vector3.hpp>

struct Spin: Engine::Component {
	Engine::Vector3<Engine::Float> axis;
	Engine::Float speed = 0;
};

#endif
