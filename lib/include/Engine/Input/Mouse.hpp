#ifndef ENGINE_MOUSE_HPP
#define ENGINE_MOUSE_HPP

#include <Engine/Maths/Vector2.hpp>
#include <GLFW/glfw3.h>

namespace Engine::Mouse {

void setup(GLFWwindow* window);

Vector2<Float> getPosition();

static Vector2<Float> position;

}

#endif
