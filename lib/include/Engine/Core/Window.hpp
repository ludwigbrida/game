#ifndef ENGINE_WINDOW_HPP
#define ENGINE_WINDOW_HPP

#include <Engine/Core/Types.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {

class Window {
public:
	Window(Int32 width, Int32 height);
	~Window();

	void setTitle(String title);

	bool isOpen() const;

	void pollEvents() const;
	void swapBuffers() const;

private:
	GLFWwindow* window;
};

}

#endif
