#ifndef ENGINE_COLLIDER_HPP
#define ENGINE_COLLIDER_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Vector3.hpp>
#include <vector>

namespace Engine {

struct Collider: Component {
	std::vector<Vector3<Float>> vertices;
};

}

#endif
