#ifndef GAME_MOVEMENT_HPP
#define GAME_MOVEMENT_HPP

#include <Engine/Maths/Vector3.hpp>
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
	Engine::Vector3<Engine::Float> worldUp = Engine::Vector3<Engine::Float>::Up;
	Engine::Vector2<Engine::Float> previousPosition = {1920.f / 2, 1080.f / 2};
	Engine::Angle<Engine::Float> yaw = -90;
	Engine::Angle<Engine::Float> pitch = 0;
};

#endif
