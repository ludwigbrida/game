#ifndef ENGINE_MESH_HPP
#define ENGINE_MESH_HPP

#include "../types_legacy/vertex.hpp"
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
											 ng::Color::Red,
										 },
										 {
											 Vector3f(-radius, -radius, 0),
											 Vector3f::backward,
											 ng::Color::Green,
										 },
										 {
											 Vector3f(radius, -radius, 0),
											 Vector3f::backward,
											 ng::Color::Blue,
										 }};
		mesh.indices = {0, 1, 2};
		return mesh;
	}
};

#endif
