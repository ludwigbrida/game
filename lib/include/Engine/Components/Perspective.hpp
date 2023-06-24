#ifndef ENGINE_PERSPECTIVE_HPP
#define ENGINE_PERSPECTIVE_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Angle.hpp>

namespace Engine {

struct Perspective: Component {
	Angle<Float> fieldOfView = 45_deg;
	Float aspectRatio = 16.f / 9.f;
	Float near = .1f;
	Float far = 1000.f;
};

}

#endif
