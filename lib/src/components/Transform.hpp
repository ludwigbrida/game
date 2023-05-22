#ifndef ENGINE_TRANSFORM_HPP
#define ENGINE_TRANSFORM_HPP

#include "../ecs/component.hpp"
#include "../math/quaternion.hpp"
#include "../math/vector.hpp"

struct Transform : Component {
	Vector3f position;
	Quaternion3f rotation;
	Vector3f scale{1, 1, 1};
};

#endif
