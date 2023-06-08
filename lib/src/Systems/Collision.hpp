#ifndef ENGINE_COLLISION_HPP
#define ENGINE_COLLISION_HPP

#include <Engine/Components/Collider.hpp>
#include <Engine/Core/System.hpp>
#include <Engine/Maths/Vector3.hpp>
#include <list>

namespace ng {

class Collision : public System {
public:
	void update(Registry& registry, State& state, Float deltaTime,
							Float elapsedTime) override;

private:
	static bool gjk(const Collider& collider1, const Collider& collider2);

	static bool nextSimplex(std::list<Vector3<Float>>& points,
													Vector3<Float>& direction);

	static bool sameDirection(const Vector3<Float>& direction1,
														const Vector3<Float>& direction2);

	static Vector3<Float> supportPoint(const Collider& collider1,
																		 const Collider& collider2,
																		 Vector3<Float> direction);

	static Vector3<Float> furthestPoint(const Collider& collider,
																			Vector3<Float> direction);
};

}

#endif
