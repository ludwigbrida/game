cmake_minimum_required(VERSION 3.24)

project(game VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(game
	# components
	src/components/mesh.hpp
	src/components/transform.hpp
	# concepts
	src/concepts/ArithmeticType.hpp
	src/concepts/ComponentType.hpp
	src/concepts/SystemType.hpp
	# core
	src/core/app/app.cpp
	src/core/app/app.hpp
	# ecs
	src/ecs/Registry/Registry.cpp
	src/ecs/Registry/Registry.hpp
	src/ecs/Entity.hpp
	src/ecs/Component.hpp
	src/ecs/System.hpp
	# maths
	src/maths/matrix.cpp
	src/maths/matrix.hpp
	src/maths/quaternion.cpp
	src/maths/quaternion.hpp
	src/maths/vector.cpp
	src/maths/vector.hpp
	# models
	src/models/vertex.hpp
	# systems
	src/systems/TransformSystem/TransformSystem.cpp
	src/systems/TransformSystem/TransformSystem.hpp
	src/systems/RenderSystem/RenderSystem.cpp
	src/systems/RenderSystem/RenderSystem.hpp
	# other
	src/main.cpp
	)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(game glfw OpenGL::GL)
