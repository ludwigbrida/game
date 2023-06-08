#include "Collision.hpp"
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>
#include <iostream>
#include <limits>

namespace ng {

void Collision::update(
	Registry& registry, State& state, Float deltaTime, Float elapsedTime) {
	auto entities = registry.view<Transform, Collider>();

	for (auto entity1: entities) {
		auto& transform1 = registry.get<Transform>(entity1);
		auto& collider1 = registry.get<Collider>(entity1);

		for (auto entity2: entities) {
			if (entity1 != entity2) {
				auto& transform2 = registry.get<Transform>(entity2);
				auto& collider2 = registry.get<Collider>(entity2);

				if (gjk(collider1, collider2)) {
					// TODO: Add transform to the colliders
					std::cout << "GJK" << std::endl;
				}
			}
		}
	}
}

bool Collision::gjk(const Collider& collider1, const Collider& collider2) {
	Vector3<Float> support =
		supportPoint(collider1, collider2, Vector3<Float>::Right);

	Simplex points;
	points.push_front(support);

	Vector3<Float> direction = -support;

	while (true) {
		support = supportPoint(collider1, collider2, direction);

		if (support.dot(direction) <= 0) {
			return false;
		}

		points.push_front(support);

		if (nextSimplex(points, direction)) {
			return true;
		}
	}
}

bool Collision::nextSimplex(Simplex& points, Vector3<Float>& direction) {
	switch (points.size()) {
	case 2:
		return line(points, direction);
	case 3:
		return triangle(points, direction);
	case 4:
		return tetrahedron(points, direction);
	}

	return false;
}

bool Collision::line(Simplex& points, Vector3<Float>& direction) {
	auto a = points[0];
	auto b = points[1];

	auto ab = b - a;
	auto ao = -a;

	if (sameDirection(ab, ao)) {
		direction = ab.cross(ao).cross(ab);
	} else {
		points = {a};
		direction = ao;
	}

	return false;
}

bool Collision::triangle(Simplex& points, Vector3<Float>& direction) {
	auto a = points[0];
	auto b = points[1];
	auto c = points[2];

	auto ab = b - a;
	auto ac = c - a;
	auto ao = -a;

	auto abc = ab.cross(ac);

	if (sameDirection(abc.cross(ac), ao)) {
		if (sameDirection(ac, ao)) {
			points = {a, c};
			direction = ac.cross(ao).cross(ac);
		} else {
			return line(points = {a, b}, direction);
		}
	} else {
		if (sameDirection(ab.cross(abc), ao)) {
			return line(points = {a, b}, direction);
		} else {
			if (sameDirection(abc, ao)) {
				direction = abc;
			} else {
				points = {a, c, b};
				direction = -abc;
			}
		}
	}

	return false;
}

bool Collision::tetrahedron(Simplex& points, Vector3<Float>& direction) {
	auto a = points[0];
	auto b = points[1];
	auto c = points[2];
	auto d = points[3];

	auto ab = b - a;
	auto ac = c - a;
	auto ad = d - a;
	auto ao = -a;

	auto abc = ab.cross(ac);
	auto acd = ac.cross(ad);
	auto adb = ad.cross(ab);

	if (sameDirection(abc, ao)) {
		return triangle(points = {a, b, c}, direction);
	}
	if (sameDirection(acd, ao)) {
		return triangle(points = {a, c, d}, direction);
	}
	if (sameDirection(adb, ao)) {
		return triangle(points = {a, d, b}, direction);
	}

	return true;
}

bool Collision::sameDirection(
	const Vector3<Float>& direction1, const Vector3<Float>& direction2) {
	return direction1.dot(direction2) > 0;
}

Vector3<Float> Collision::supportPoint(const Collider& collider1,
	const Collider& collider2, Vector3<Float> direction) {
	return furthestPoint(collider1, direction) -
		furthestPoint(collider2, -direction);
}

Vector3<Float> Collision::furthestPoint(
	const Collider& collider, Vector3<Float> direction) {
	Vector3<Float> maxPoint;
	Float maxDistance = -std::numeric_limits<Float>::max();

	for (auto vertex: collider.vertices) {
		auto distance = vertex.dot(direction);

		if (distance > maxDistance) {
			maxDistance = distance;
			maxPoint = vertex;
		}
	}

	return maxPoint;
}

}
