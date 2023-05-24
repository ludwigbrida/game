#ifndef ENGINE_PERSPECTIVE_HPP
#define ENGINE_PERSPECTIVE_HPP

#include "../ecs/component.hpp"
#include "../types_legacy/primitive.hpp"

struct Perspective : Component {
	Float fieldOfView;
	Float aspectRatio;
	Float near = .1;
	Float far = 1000;
};

#endif
