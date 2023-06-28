project(app VERSION 0.0.0)

add_executable(app
	# Components
	src/Components/Spin.hpp
	# Core
	src/Core/Game.cpp
	src/Core/Game.hpp
	# Systems
	src/Systems/Movement.cpp
	src/Systems/Movement.hpp
	src/Systems/Rotation.cpp
	src/Systems/Rotation.hpp
	# other
	src/main.cpp)

target_link_libraries(app PRIVATE lib)
