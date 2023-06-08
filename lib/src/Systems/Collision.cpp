#include "Collision.hpp"
#include <limits>

namespace ng {

Vector3<Float> Collision::furthestPoint(const Collider& vertices,
																				Vector3<Float> direction) {
	Vector3<Float> maxPoint;
	Float maxDistance = -std::numeric_limits<Float>::max();

	for (auto vertex : vertices.vertices) {
		auto distance = vertex.dot(direction);

		if (distance > maxDistance) {
			maxDistance = distance;
			maxPoint = vertex;
		}
	}

	return maxPoint;
}

Vector3<Float> Collision::support(const Collider& collider1,
																	const Collider& collider2,
																	Vector3<Float> direction) {
	return furthestPoint(collider1, direction) -
				 furthestPoint(collider2, -direction);
}

}
