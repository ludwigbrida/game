project(lib VERSION 0.0.0)

add_library(lib
	# components
	src/components/Mesh.hpp
	src/components/Perspective.hpp
	src/components/Transform.hpp
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
	src/gfx/Color.cpp
	src/gfx/Color.hpp
	src/gfx/shader.cpp
	src/gfx/shader.hpp
	# Maths
	src/math/matrix.cpp
	src/math/matrix.hpp
	src/math/quaternion.cpp
	src/math/quaternion.hpp
	src/math/radian.hpp
	src/math/vector.cpp
	src/math/vector.hpp
	# systems
	src/systems/renderer.cpp
	src/systems/renderer.hpp
	src/systems/transformer.cpp
	src/systems/transformer.hpp
	# types_legacy
	src/types_legacy/arithmetic.hpp
	src/types_legacy/composable.hpp
	src/types_legacy/primitive.hpp
	src/types_legacy/systemic.hpp
	src/types_legacy/vertex.hpp
	# other
	include/Engine/Types/Scalar.hpp include/Engine/Maths/Vector3.hpp src/Maths/Vector3.cpp include/Engine/Graphics/Color.hpp include/Engine/Types/IsArithmetic.hpp src/Graphics/Color.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(lib OpenGL::GL glfw GLEW::GLEW)

target_include_directories(lib
	PUBLIC
	include
	PRIVATE
	src)
