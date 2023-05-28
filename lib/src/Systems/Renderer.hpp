#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

#include <Engine/Core/System.hpp>

namespace ng {

class Renderer : System {
public:
	void update(Registry& registry, State& state, float deltaTime) override;
};

}

#endif
