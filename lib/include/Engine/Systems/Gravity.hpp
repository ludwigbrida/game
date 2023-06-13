#ifndef ENGINE_GRAVITY_HPP
#define ENGINE_GRAVITY_HPP

#include <Engine/Core/System.hpp>

namespace ng {

class Gravity: public System {
public:
	Gravity(Float acceleration): acceleration{acceleration} {}

	void update(Registry& registry, State& state, const Clock& clock) override;

private:
	Float acceleration;
};

}

#endif
