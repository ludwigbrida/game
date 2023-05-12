#ifndef GAME_MESH_HPP
#define GAME_MESH_HPP

#include "../ecs/component.hpp"
#include "../types/vertex.hpp"
#include <vector>

struct Mesh : Component {
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	static Mesh createTriangle(float size) {
		auto mesh = Mesh();
		float radius = size / 2;
		mesh.vertices = {{
											 Vector3f(0, radius, 0),
											 Vector3f::backward,
											 Vector3f(1, 0, 0),
										 },
										 {
											 Vector3f(-radius, -radius, 0),
											 Vector3f::backward,
											 Vector3f(0, 1, 0),
										 },
										 {
											 Vector3f(radius, -radius, 0),
											 Vector3f::backward,
											 Vector3f(0, 0, 1),
										 }};
		mesh.indices = {0, 1, 2};
		return mesh;
	}
};

#endif
