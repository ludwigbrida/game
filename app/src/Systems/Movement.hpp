#ifndef GAME_MOVEMENT_HPP
#define GAME_MOVEMENT_HPP

#include <Engine/Core/System.hpp>
#include <Engine/Maths/Angle.hpp>
#include <Engine/Maths/Vector2.hpp>

class Movement: public Engine::System {
public:
	void run(
		Engine::Registry& registry,
		Engine::State& state,
		const Engine::Clock& clock
	) override;

private:
	Engine::Vector2<Engine::Float> previousPosition = {0, 0};
	Engine::Angle<Engine::Float> yaw = 0;
	Engine::Angle<Engine::Float> pitch = 0;
};

#endif
