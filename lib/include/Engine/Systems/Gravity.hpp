#ifndef ENGINE_GRAVITY_HPP
#define ENGINE_GRAVITY_HPP

#include <Engine/Core/System.hpp>

namespace ng {

// TODO: Why doesn't inheritance work properly without "public"
class Gravity: public System {
public:
	void update(Registry& registry, State& state, const Clock& clock) override;

	Float acceleration{};
};

}

#endif
