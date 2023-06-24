#ifndef ENGINE_MASS_HPP
#define ENGINE_MASS_HPP

#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Core/Component.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace Engine {

struct Physics: Component {
	Vector3<Float> velocity{};
	Vector3<Float> acceleration{};
	Float mass{1};
};

}

#endif
