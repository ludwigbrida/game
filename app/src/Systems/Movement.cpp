#include "Movement.hpp"
#include <Engine/Components/Camera.hpp>
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Core/State.hpp>
#include <Engine/Input/Keyboard.hpp>
#include <Engine/Input/Mouse.hpp>
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

	Engine::Vector2<Engine::Float> offset = {
		static_cast<Engine::Float>(Engine::Mouse::getPosition().x) -
			previousPosition.x,
		previousPosition.y -
			static_cast<Engine::Float>(Engine::Mouse::getPosition().y),
	};

	previousPosition = Engine::Mouse::getPosition();

	Engine::Float sensitivity = 0.1f;
	offset *= sensitivity;

	yaw += offset.x;
	pitch += offset.y;

	if (pitch > 89.f) {
		pitch = 89.f;
	}
	if (pitch < -89.f) {
		pitch = -89.f;
	}

	Engine::Vector3<Engine::Float> direction;
	direction.x = std::cos(yaw.asRadians()) * std::cos(pitch.asRadians());
	direction.y = std::sin(pitch.asRadians());
	direction.z = std::sin(yaw.asRadians()) * std::cos(pitch.asRadians());

	camera.forward = direction.normalized();
}
