cmake_minimum_required(VERSION 3.20)
project(projectzvum)

add_subdirectory(SDL3)

add_executable(projectzvum src/main.c)

target_link_libraries(projectzvum PRIVATE SDL3::SDL3)

add_custom_command(
	TARGET myproject POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/assets
		$<TARGET_FILE_DIR:projectzvum>/assets
)
