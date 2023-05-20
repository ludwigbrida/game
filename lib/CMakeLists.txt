project(lib VERSION 0.0.0)

add_library(lib
	# components
	src/components/mesh.hpp
	src/components/perspective.hpp
	src/components/transform.hpp
	# core
	src/core/app.cpp
	src/core/app.hpp
	src/core/State.hpp
	# ecs
	src/ecs/component.hpp
	src/ecs/entity.hpp
	src/ecs/registry.cpp
	src/ecs/registry.hpp
	src/ecs/system.hpp
	# graphics
	src/graphics/Color.cpp
	src/graphics/Color.hpp
	src/graphics/shader.cpp
	src/graphics/shader.hpp
	# maths
	src/maths/matrix.cpp
	src/maths/matrix.hpp
	src/maths/quaternion.cpp
	src/maths/quaternion.hpp
	src/maths/radian.hpp
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
	src/types/vertex.hpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(lib OpenGL::GL glfw GLEW::GLEW)
