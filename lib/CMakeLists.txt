project(lib VERSION 0.0.0)

add_library(lib
	# include
	# Components
	include/Engine/Components/Perspective.hpp
	include/Engine/Components/Transform.hpp
	# Core
	include/Engine/Core/App.hpp
	include/Engine/Core/Arithmetic.hpp
	include/Engine/Core/Component.hpp
	include/Engine/Core/Entity.hpp
	include/Engine/Core/State.hpp
	include/Engine/Core/System.hpp
	# Graphics
	include/Engine/Graphics/Color.hpp
	include/Engine/Graphics/Vertex.hpp
	# Maths
	include/Engine/Maths/Matrix4.hpp
	include/Engine/Maths/Matrix4.inl
	include/Engine/Maths/Vector3.hpp
	include/Engine/Maths/Vector3.inl
	# src
	# Core
	src/Core/App.cpp
	src/Core/Registry.cpp
	src/Core/Registry.hpp
	src/Core/Registry.inl
	src/Core/System.cpp
	# Graphics
	src/Graphics/Color.cpp
	# Maths
	src/Maths/Matrix4.cpp
	src/Maths/Vector3.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(lib OpenGL::GL glfw GLEW::GLEW)

target_include_directories(lib
	PUBLIC
	include
	PRIVATE
	src)
