#ifndef GAME_MESH_HPP
#define GAME_MESH_HPP

#include "../ecs/component.hpp"
#include "../types/vertex.hpp"
#include <vector>

struct Mesh : Component {
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	static Mesh fromVertices(const std::vector<Vertex>& vertices,
													 const std::vector<unsigned int>& indices) {
		auto mesh = Mesh();
		for (const auto& vertex : vertices) {
			mesh.vertices.push_back(vertex.position.x);
			mesh.vertices.push_back(vertex.position.y);
			mesh.vertices.push_back(vertex.position.z);
			mesh.vertices.push_back(vertex.normal.x);
			mesh.vertices.push_back(vertex.normal.y);
			mesh.vertices.push_back(vertex.normal.z);
			mesh.vertices.push_back(vertex.color.x);
			mesh.vertices.push_back(vertex.color.y);
			mesh.vertices.push_back(vertex.color.z);
		}
		mesh.indices = indices;
		return mesh;
	}

	static Mesh createTriangle(float size) {
		float radius = size / 2;
		return fromVertices({{
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
												 }},
												{0, 1, 2});
	}
};

#endif
