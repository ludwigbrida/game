#ifndef ENGINE_TRANSFORMER_HPP
#define ENGINE_TRANSFORMER_HPP

#include <Engine/Core/System.hpp>

namespace ng {

class Transformer : public System {
public:
	void update(Registry& matrices, State& state, Float deltaTime,
							Float elapsedTime) override;
};

}

#endif
