#ifndef ENGINE_CAMERA_HPP
#define ENGINE_CAMERA_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Angle.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace Engine {

struct Camera: Component {
	Vector3<Float> forward;
	Angle<Float> fieldOfView = 45_deg;
	Float aspectRatio = 16.f / 9.f;
	Float near = .1f;
	Float far = 1000.f;
};

}

#endif
