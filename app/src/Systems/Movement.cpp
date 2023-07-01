#include "Movement.hpp"
#include <Engine/Components/Camera.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>
#include <Engine/Input/Keyboard.hpp>
#include <Engine/Maths/Vector3.hpp>

void Movement::run(
	Engine::Registry& registry,
	Engine::State& state,
	const Engine::Clock& clock
) {
	const auto speed = 10 * clock.deltaTime;

	auto& transform = registry.get<Engine::Transform>(state.activeCamera);
	auto& camera = registry.get<Engine::Camera>(state.activeCamera);

	// auto forward = Engine::Vector3<Engine::Float>::Zero;
	// auto right = Engine::Vector3<Engine::Float>::Zero;

	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::W)) {
		// forward = Engine::Vector3<Engine::Float>::Forward;
		transform.position += camera.forward * speed;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::S)) {
		// forward = -Engine::Vector3<Engine::Float>::Forward;
		transform.position -= camera.forward * speed;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::D)) {
		// right = Engine::Vector3<Engine::Float>::Right;
		transform.position +=
			camera.forward.cross(Engine::Vector3<Engine::Float>::Up).normalized() *
			speed;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::A)) {
		// right = -Engine::Vector3<Engine::Float>::Right;
		transform.position -=
			camera.forward.cross(Engine::Vector3<Engine::Float>::Up).normalized() *
			speed;
	}

	// transform.position += (forward + right) * 10 * clock.deltaTime;
}
