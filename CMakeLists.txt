cmake_minimum_required(VERSION 3.24)

project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game
	src/main.cpp
	src/maths/Matrix/Matrix.cpp
	src/maths/Matrix/Matrix.hpp
	src/maths/Quaternion/Quaternion.cpp
	src/maths/Quaternion/Quaternion.hpp
	src/maths/Vector/Vector.cpp
	src/maths/Vector/Vector.hpp src/ecs/Registry/Registry.cpp src/ecs/Registry/Registry.hpp src/ecs/System/System.cpp src/ecs/System/System.hpp src/components/TransformComponent.hpp)
