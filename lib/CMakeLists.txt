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
	src/types/vertex.hpp
	# other
	include/Engine/UInt.hpp include/Engine/maths/Vector3.hpp include/Engine/maths/Vector3.inl src/maths/Vector3.cpp include/Engine/Graphics/Color.hpp src/Graphics/Color.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(lib OpenGL::GL glfw GLEW::GLEW)

target_include_directories(lib
	PUBLIC
	include
	PRIVATE
	src)
