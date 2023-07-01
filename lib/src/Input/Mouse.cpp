#include <Engine/Core/Arithmetic.hpp>
#include <Engine/Input/Mouse.hpp>
#include <Engine/Maths/Angle.hpp>
#include <Engine/Maths/Vector3.hpp>

namespace Engine::Mouse {

Float lastX = 1920.f / 2, lastY = 1080.f / 2;

Float yaw = 0, pitch = 0;

void cursorPositionCallback(
	GLFWwindow* window,
	double positionX,
	double positionY
) {
	Float offsetX = static_cast<Float>(positionX) - lastX;
	Float offsetY = lastY - static_cast<Float>(positionY);

	lastX = static_cast<Float>(positionX);
	lastY = static_cast<Float>(positionY);

	Float sensitivity = 0.1f;
	offsetX *= sensitivity;
	offsetY *= sensitivity;

	yaw += offsetX;
	pitch += offsetY;

	if (pitch >= 90.f) {
		pitch = 90.f;
	}
	if (pitch <= -90.f) {
		pitch = -90.f;
	}

	Vector3<Float> direction;
	direction.x =
		std::cos(Angle(yaw).asRadians()) * std::cos(Angle(pitch).asRadians());
	direction.y = std::sin(Angle(pitch).asRadians());
	direction.z =
		std::sin(Angle(yaw).asRadians()) * std::cos(Angle(pitch).asRadians());

	Vector3<Float> cameraFront = direction.normalized();
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {}
}

void setup(GLFWwindow* window) {
	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

}
