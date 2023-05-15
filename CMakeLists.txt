cmake_minimum_required(VERSION 3.24)

project(game VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(game
	# components
	src/components/mesh.hpp
	src/components/transform.hpp
	# core
	src/core/app.cpp
	src/core/app.hpp
	# ecs
	src/ecs/component.hpp
	src/ecs/entity.hpp
	src/ecs/registry.cpp
	src/ecs/registry.hpp
	src/ecs/system.hpp
	# graphics
	src/graphics/color.cpp
	src/graphics/color.hpp
	src/graphics/shader.cpp
	src/graphics/shader.hpp
	# maths
	src/maths/matrix.cpp
	src/maths/matrix.hpp
	src/maths/quaternion.cpp
	src/maths/quaternion.hpp
	src/maths/vector.cpp
	src/maths/vector.hpp
	# systems
	src/systems/renderer.cpp
	src/systems/renderer.hpp
	src/systems/transformer.cpp
	src/systems/transformer.hpp
	# types
	src/types/arithmetic.hpp
	src/types/composable.hpp
	src/types/primitive.hpp
	src/types/systemic.hpp
	src/types/vertex.hpp
	# other
	src/main.cpp src/components/perspective.hpp src/maths/radian.hpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(game OpenGL::GL glfw GLEW::GLEW)
