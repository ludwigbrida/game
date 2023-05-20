project(app)

add_executable(app
	# other
	src/main.cpp)

target_link_libraries(app PRIVATE lib)
