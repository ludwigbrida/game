#ifndef GAME_MOVEMENT_HPP
#define GAME_MOVEMENT_HPP

#include <Engine/Core/System.hpp>

class Movement: public ng::System {
public:
	void update(ng::Registry& registry, ng::State& state, const ng::Clock& clock)
		override;
};

#endif
