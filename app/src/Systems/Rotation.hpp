#ifndef GAME_ROTATION_HPP
#define GAME_ROTATION_HPP

#include <Engine/Core/System.hpp>

class Rotation: public Engine::System {
public:
	void run(
		Engine::Registry& registry,
		Engine::State& state,
		const Engine::Clock& clock
	) override;
};

#endif
