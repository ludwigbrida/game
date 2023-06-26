#include "Movement.hpp"
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>
#include <Engine/Input/Keyboard.hpp>

void Movement::run(
	Engine::Registry& registry,
	Engine::State& state,
	const Engine::Clock& clock
) {
	auto forward = Engine::Vector3<Engine::Float>::Zero;
	auto right = Engine::Vector3<Engine::Float>::Zero;

	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::W)) {
		forward = Engine::Vector3<Engine::Float>::Forward;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::S)) {
		forward = -Engine::Vector3<Engine::Float>::Forward;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::D)) {
		right = Engine::Vector3<Engine::Float>::Right;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::A)) {
		right = -Engine::Vector3<Engine::Float>::Right;
	}

	auto& transform = registry.get<Engine::Transform>(state.activeCamera);

	transform.position += (forward + right) * 10 * clock.deltaTime;
}
