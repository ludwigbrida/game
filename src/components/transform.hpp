#ifndef GAME_TRANSFORM_HPP
#define GAME_TRANSFORM_HPP

#include "../ecs/component.hpp"
#include "../maths/quaternion.hpp"
#include "../maths/vector.hpp"

struct Transform : Component {
	Vector3f position;
	Quaternion3f rotation;
	Vector3f scale;
};

#endif
