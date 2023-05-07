#ifndef GAME_MESH_COMPONENT_HPP
#define GAME_MESH_COMPONENT_HPP

#include "../ecs/Component.hpp"
#include "../models/Vertex.hpp"
#include <vector>

struct MeshComponent : public Component {
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	static MeshComponent createTriangle(float size) {
		auto meshComponent = MeshComponent();
		float radius = size / 2;
		meshComponent.vertices = {{
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
		meshComponent.indices = {0, 1, 2};
		return meshComponent;
	}
};

#endif
