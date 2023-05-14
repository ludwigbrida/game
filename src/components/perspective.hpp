#ifndef GAME_PERSPECTIVE_HPP
#define GAME_PERSPECTIVE_HPP

#include "../ecs/component.hpp"
#include "../types/primitive.hpp"

struct Perspective : Component {
	Float fieldOfView;
	Float aspectRatio;
	Float near;
	Float far;
};

#endif
