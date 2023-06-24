#ifndef ENGINE_GRAVITY_HPP
#define ENGINE_GRAVITY_HPP

#include <Engine/Core/System.hpp>

namespace Engine {

class Gravity: public System {
public:
	Gravity(Float constant): constant{Vector3<Float>::Down * constant} {}

	void update(Registry& registry, State& state, const Clock& clock) override;

private:
	Vector3<Float> constant;
};

}

#endif
