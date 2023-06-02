#ifndef ENGINE_TRANSFORMER_HPP
#define ENGINE_TRANSFORMER_HPP

#include <Engine/Core/System.hpp>

namespace ng {

class Transformer : public System {
public:
	void update(ng::Registry& matrices, ng::State& state,
							ng::Float deltaTime) override;
};

}

#endif
