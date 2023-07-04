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
	auto& transform = registry.get<Engine::Transform>(state.activeCamera);
	auto& camera = registry.get<Engine::Camera>(state.activeCamera);

	const auto velocity = 10 * clock.deltaTime;

	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::W)) {
		transform.position += camera.forward * velocity;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::S)) {
		transform.position -= camera.forward * velocity;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::D)) {
		transform.position += camera.right * velocity;
	}
	if (Engine::Keyboard::isKeyPressed(Engine::Keyboard::Key::A)) {
		transform.position -= camera.right * velocity;
	}

	// TODO
	Engine::Vector2<Engine::Float> offset = {
		Engine::Mouse::getPosition().x - previousPosition.x,
		previousPosition.y - Engine::Mouse::getPosition().y,
	};

	// TODO
	previousPosition = Engine::Mouse::getPosition();

	const auto sensitivity = 0.1f;
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
	camera.right = camera.forward.cross(worldUp).normalized();
	// camera.right = worldUp.cross(camera.forward).normalized();
	camera.up = camera.right.cross(camera.forward).normalized();
	// camera.up = camera.forward.cross(camera.right).normalized();
}
