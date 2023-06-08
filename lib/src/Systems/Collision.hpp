#ifndef ENGINE_COLLISION_HPP
#define ENGINE_COLLISION_HPP

#include <Engine/Components/Collider.hpp>
#include <Engine/Core/System.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace ng {

class Collision : public System {
private:
	static Vector3<Float> furthestPoint(const Collider& vertices,
																			Vector3<Float> direction);

	static Vector3<Float> support(const Collider& collider1,
																const Collider& collider2,
																Vector3<Float> direction);
};

}

#endif
