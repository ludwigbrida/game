#ifndef ENGINE_TRANSFORM_HPP
#define ENGINE_TRANSFORM_HPP

#include <Engine/Maths/Vector3.hpp>

namespace ng {

struct Transform {
	Vector3f position;
	// Quaternion rotation;
	Vector3f scale{1, 1, 1};
};

}

#endif
