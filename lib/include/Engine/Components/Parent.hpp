#ifndef ENGINE_PARENT_HPP
#define ENGINE_PARENT_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Core/Entity.hpp>

namespace ng {

struct Parent: Component {
	Entity entity{};
};

}

#endif
