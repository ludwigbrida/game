#ifndef ENGINE_PERSPECTIVE_HPP
#define ENGINE_PERSPECTIVE_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Angle.hpp>

namespace Engine {

struct Perspective: Component {
	Angle<Float> fieldOfView;
	Float aspectRatio{};
	Float near{.1};
	Float far{1000};
};

}

#endif
