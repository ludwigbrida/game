#include "Movement.hpp"
#include <Engine/Components/Transform.hpp>
#include <Engine/Core/Registry.hpp>
#include <Engine/Input/Keyboard.hpp>

void Movement::update(ng::Registry& registry, ng::State& state,
											ng::Float deltaTime, ng::Float elapsedTime) {
	// Velocities
	auto forward = ng::Vector3<ng::Float>::Zero;
	auto right = ng::Vector3<ng::Float>::Zero;

	if (ng::Keyboard::isKeyPressed(ng::Keyboard::Key::W)) {
		forward = ng::Vector3<ng::Float>::Forward;
	}
	if (ng::Keyboard::isKeyPressed(ng::Keyboard::Key::S)) {
		forward = -ng::Vector3<ng::Float>::Forward;
	}
	if (ng::Keyboard::isKeyPressed(ng::Keyboard::Key::D)) {
		right = ng::Vector3<ng::Float>::Right;
	}
	if (ng::Keyboard::isKeyPressed(ng::Keyboard::Key::A)) {
		right = -ng::Vector3<ng::Float>::Right;
	}

	registry.update<ng::Transform>(
		state.activeCamera, [=](ng::Transform& transform) {
			transform.position += (forward + right) * 10 * deltaTime;
		});
}
