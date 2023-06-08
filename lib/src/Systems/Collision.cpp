#include "Collision.hpp"
#include <limits>
#include <list>

namespace ng {

void Collision::update(Registry& registry, State& state, Float deltaTime,
											 Float elapsedTime) {}

bool Collision::gjk(const Collider& collider1, const Collider& collider2) {
	Vector3<Float> support =
		supportPoint(collider1, collider2, Vector3<Float>::Right);

	std::list<Vector3<Float>> points;
	points.push_front(support);

	Vector3<Float> direction = -support;

	while (true) {
		support = supportPoint(collider1, collider2, direction);

		if (support.dot(direction) <= 0) {
			return false;
		}
	}
}

Vector3<Float> Collision::supportPoint(const Collider& collider1,
																			 const Collider& collider2,
																			 Vector3<Float> direction) {
	return furthestPoint(collider1, direction) -
				 furthestPoint(collider2, -direction);
}

Vector3<Float> Collision::furthestPoint(const Collider& collider,
																				Vector3<Float> direction) {
	Vector3<Float> maxPoint;
	Float maxDistance = -std::numeric_limits<Float>::max();

	for (auto vertex : collider.vertices) {
		auto distance = vertex.dot(direction);

		if (distance > maxDistance) {
			maxDistance = distance;
			maxPoint = vertex;
		}
	}

	return maxPoint;
}

}
