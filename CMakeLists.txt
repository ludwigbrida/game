cmake_minimum_required(VERSION 3.24)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game
	src/main.cpp src/models/Vector/Vector.cpp src/models/Vector/Vector.hpp src/models/Matrix/Matrix.cpp src/models/Matrix/Matrix.hpp)
