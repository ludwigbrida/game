#ifndef ENGINE_PARENT_HPP
#define ENGINE_PARENT_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Core/Entity.hpp>

namespace Engine {

struct Parent: Component {
	Entity entity{};
};

}

#endif
