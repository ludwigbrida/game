#ifndef ENGINE_TRANSFORM_HPP
#define ENGINE_TRANSFORM_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Quaternion.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace ng {

struct Transform : Component {
	Vector3f position;
	Quaternion<Float> rotation;
	Vector3f scale{1, 1, 1};
};

}

#endif
