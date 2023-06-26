#ifndef ENGINE_TRANSFORM_HPP
#define ENGINE_TRANSFORM_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Quaternion.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace Engine {

struct Transform: Component {
	Vector3<Float> position;
	Quaternion<Float> rotation;
	Vector3<Float> scale = {1, 1, 1};
};

}

#endif
