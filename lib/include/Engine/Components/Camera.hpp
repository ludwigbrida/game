#ifndef ENGINE_CAMERA_HPP
#define ENGINE_CAMERA_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Angle.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace Engine {

struct Camera: Component {
	Vector3<Float> forward = Vector3<Float>::Forward;
	Vector3<Float> right = Vector3<Float>::Right;
	Vector3<Float> up = Vector3<Float>::Up;
	Angle<Float> fieldOfView = 110_deg;
	Float aspectRatio = 16.f / 9.f;
	Float near = .1f;
	Float far = 1000.f;
};

}

#endif
