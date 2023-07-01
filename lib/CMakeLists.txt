project(lib VERSION 0.0.0)

add_library(lib
	# include
	# Components
	include/Engine/Components/Camera.hpp
	include/Engine/Components/Collider.hpp
	include/Engine/Components/Physics.hpp
	include/Engine/Components/Matrices.hpp
	include/Engine/Components/Mesh.hpp
	include/Engine/Components/Parent.hpp
	include/Engine/Components/Transform.hpp
	# Core
	include/Engine/Core/Application.hpp
	include/Engine/Core/Arithmetic.hpp
	include/Engine/Core/Clock.hpp
	include/Engine/Core/Component.hpp
	include/Engine/Core/Entity.hpp
	include/Engine/Core/Registry.hpp
	include/Engine/Core/State.hpp
	include/Engine/Core/System.hpp
	include/Engine/Core/Types.hpp
	include/Engine/Core/Window.hpp
	# Graphics
	include/Engine/Graphics/Color.hpp
	include/Engine/Graphics/Vertex.hpp
	# Input
	include/Engine/Input/Keyboard.hpp
	# Maths
	include/Engine/Maths/Angle.hpp
	include/Engine/Maths/Matrix4.hpp
	include/Engine/Maths/Quaternion.hpp
	include/Engine/Maths/Vector2.hpp
	include/Engine/Maths/Vector3.hpp
	include/Engine/Maths/Vector3.inl
	# Systems
	include/Engine/Systems/Gravity.hpp
	# src
	# Components
	src/Components/Mesh.cpp
	# Core
	src/Core/Application.cpp
	src/Core/Registry.cpp
	src/Core/System.cpp
	src/Core/Window.cpp
	# Graphics
	src/Graphics/Color.cpp
	src/Graphics/CubeMap.cpp
	src/Graphics/CubeMap.hpp
	src/Graphics/Material.cpp
	src/Graphics/Material.hpp
	src/Graphics/Shader.cpp
	src/Graphics/Shader.hpp
	src/Graphics/Texture.cpp
	src/Graphics/Texture.hpp
	src/Graphics/VertexArray.cpp
	src/Graphics/VertexArray.hpp
	# Input
	src/Input/Keyboard.cpp
	# Maths
	src/Maths/Angle.cpp
	src/Maths/Matrix4.cpp
	src/Maths/Quaternion.cpp
	src/Maths/Vector2.cpp
	src/Maths/Vector3.cpp
	# Platform
	src/Platform/File.cpp
	src/Platform/File.hpp
	# Systems
	src/Systems/Collision.cpp
	src/Systems/Collision.hpp
	src/Systems/Gravity.cpp
	src/Systems/Renderer.cpp
	src/Systems/Renderer.hpp
	src/Systems/Simplex.hpp
	src/Systems/Transformer.cpp
	src/Systems/Transformer.hpp src/Graphics/TextureCube.cpp src/Graphics/TextureCube.hpp src/Graphics/VertexArrayCube.cpp src/Graphics/VertexArrayCube.hpp include/Engine/Input/Mouse.hpp src/Input/Mouse.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Stb REQUIRED)

target_link_libraries(lib OpenGL::GL glfw GLEW::GLEW)

target_include_directories(lib
	PUBLIC
	include
	PRIVATE
	src)

file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/app/assets SYMBOLIC)
