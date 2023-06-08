project(app VERSION 0.0.0)

add_executable(app
	# Systems
	src/Systems/Movement.cpp
	src/Systems/Movement.hpp
	# other
	src/main.cpp)

target_link_libraries(app PRIVATE lib)
