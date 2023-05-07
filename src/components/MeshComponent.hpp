#ifndef GAME_MESH_COMPONENT_HPP
#define GAME_MESH_COMPONENT_HPP

#include "../ecs/Component.hpp"
#include "../models/Vertex.hpp"
#include <vector>

struct MeshComponent : public Component {
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
};

#endif
