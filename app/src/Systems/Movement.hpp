#ifndef GAME_MOVEMENT_HPP
#define GAME_MOVEMENT_HPP

#include <Engine/Core/System.hpp>

class Movement: public Engine::System {
public:
	void run(
		Engine::Registry& registry,
		Engine::State& state,
		const Engine::Clock& clock
	) override;
};

#endif
