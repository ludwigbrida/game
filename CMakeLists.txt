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
	src/ecs/component.hpp
	src/ecs/entity.hpp
	src/ecs/registry.cpp
	src/ecs/registry.hpp
	src/ecs/system.hpp
	# graphics
	src/graphics/shader.cpp
	src/graphics/shader.hpp
	# maths
	src/maths/matrix.cpp
	src/maths/matrix.hpp
	src/maths/quaternion.cpp
	src/maths/quaternion.hpp
	src/maths/vector.cpp
	src/maths/vector.hpp
	# models
	src/models/color.cpp
	src/models/color.hpp
	src/models/types.hpp
	src/models/vertex.hpp
	# systems
	src/systems/renderer.cpp
	src/systems/renderer.hpp
	src/systems/transformer.cpp
	src/systems/transformer.hpp
	# other
	src/main.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(game glfw OpenGL::GL)
