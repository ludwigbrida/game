project(app VERSION 0.0.0)

add_executable(app
	# other
	src/main.cpp)

target_link_libraries(app PRIVATE lib)
