#ifndef ENGINE_MESH_HPP
#define ENGINE_MESH_HPP

#include "../types_legacy/vertex.hpp"
#include <Engine/Graphics/Color.hpp>
#include <Engine/Maths/Vector3.hpp>
#include <vector>

struct Mesh : Component {
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	static Mesh createTriangle(float size) {
		auto mesh = Mesh();
		float radius = size / 2;
		mesh.vertices = {{
											 ng::Vector3f(0, radius, 0),
											 ng::Vector3f::Backward,
											 ng::Color::Red,
										 },
										 {
											 ng::Vector3f(-radius, -radius, 0),
											 ng::Vector3f::Backward,
											 ng::Color::Green,
										 },
										 {
											 ng::Vector3f(radius, -radius, 0),
											 ng::Vector3f::Backward,
											 ng::Color::Blue,
										 }};
		mesh.indices = {0, 1, 2};
		return mesh;
	}
};

#endif
