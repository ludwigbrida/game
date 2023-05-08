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
	src/core/app.cpp
	src/core/app.hpp
	# ecs
	src/ecs/registry.cpp
	src/ecs/registry.hpp
	src/ecs/entity.hpp
	src/ecs/component.hpp
	src/ecs/system.hpp
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
