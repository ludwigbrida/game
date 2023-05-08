#ifndef GAME_TRANSFORM_HPP
#define GAME_TRANSFORM_HPP

#include "../ecs/Component.hpp"
#include "../maths/quaternion.hpp"
#include "../maths/vector.hpp"

struct Transform : public Component {
	Vector3f position;
	Quaternion3f rotation;
	Vector3f scale;
};

#endif
