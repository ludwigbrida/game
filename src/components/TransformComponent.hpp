#ifndef GAME_TRANSFORM_COMPONENT_HPP
#define GAME_TRANSFORM_COMPONENT_HPP

#include "../ecs/Component.hpp"
#include "../maths/Quaternion/Quaternion.hpp"
#include "../maths/Vector/Vector.hpp"

struct TransformComponent : public Component {
	Vector3f position;
	Quaternion3f rotation;
	Vector3f scale;
};

#endif
