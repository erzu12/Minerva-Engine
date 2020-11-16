cmake_minimum_required(VERSION 3.17.2)

project(minerva)

add_subdirectory(src)

add_subdirectory(external/glfw)
add_subdirectory(external/glm)

find_package(Vulkan REQUIRED FATAL_ERROR)

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

target_include_directories("${PROJECT_NAME}"
	PUBLIC ${Vulkan_INCLUDE_DIRS}
	PUBLIC src/log
	PUBLIC src/vulkan
	PUBLIC external/glfw/inculde
	PUBLIC external/glm
)

target_link_libraries("${PROJECT_NAME}"
	log
	vulkan
	glfw
	opengl32
	glm
)