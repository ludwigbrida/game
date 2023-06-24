#ifndef ENGINE_TRANSFORMER_HPP
#define ENGINE_TRANSFORMER_HPP

#include <Engine/Core/System.hpp>

namespace Engine {

class Transformer: public System {
public:
	void run(Registry& matrices, State& state, const Clock& clock) override;
};

}

#endif
