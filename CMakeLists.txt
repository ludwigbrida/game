cmake_minimum_required(VERSION 3.24)

project(game VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(game
	src/main.cpp
	src/maths/Matrix/Matrix.cpp
	src/maths/Matrix/Matrix.hpp
	src/maths/Quaternion/Quaternion.cpp
	src/maths/Quaternion/Quaternion.hpp
	src/maths/Vector/Vector.cpp
	src/maths/Vector/Vector.hpp
	src/ecs/Registry/Registry.cpp
	src/ecs/Registry/Registry.hpp
	src/ecs/Entity.hpp
	src/ecs/Component.hpp
	src/components/TransformComponent.hpp
	src/ecs/System.hpp
	src/systems/TransformSystem/TransformSystem.cpp
	src/systems/TransformSystem/TransformSystem.hpp
	src/concepts/ArithmeticType.hpp
	src/concepts/ComponentType.hpp
	src/concepts/SystemType.hpp
	src/components/MeshComponent.hpp
	src/models/Vertex.hpp
	src/systems/RenderSystem/RenderSystem.cpp
	src/systems/RenderSystem/RenderSystem.hpp src/core/App/App.cpp src/core/App/App.hpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(game glfw OpenGL::GL)
