#ifndef GAME_TRANSFORM_COMPONENT_HPP
#define GAME_TRANSFORM_COMPONENT_HPP

#include "../maths/Quaternion/Quaternion.hpp"
#include "../maths/Vector/Vector.hpp"
#include "Component.hpp"

struct TransformComponent : Component {
	Vector3f position;
	Quaternion3f rotation;
	Vector3f scale;
};

#endif
