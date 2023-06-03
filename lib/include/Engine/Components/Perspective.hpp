#ifndef ENGINE_PERSPECTIVE_HPP
#define ENGINE_PERSPECTIVE_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>

namespace ng {

struct Perspective : Component {
	Float fieldOfView{};
	Float aspectRatio{};
	Float near{};
	Float far{};
};

}

#endif
