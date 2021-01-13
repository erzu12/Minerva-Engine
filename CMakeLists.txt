cmake_minimum_required(VERSION 3.16.2)

project(minerva)

add_subdirectory(src/engine)
add_subdirectory(testapp)

add_subdirectory(external/glfw)
add_subdirectory(external/glm)

find_package(Vulkan REQUIRED FATAL_ERROR)

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)


target_include_directories("${PROJECT_NAME}"
	PUBLIC ${Vulkan_INCLUDE_DIRS}
	PUBLIC src/engine/log
	PUBLIC src/engine/core
	PUBLIC src/engine/vulkan
	PUBLIC external/glfw/inculde
	PUBLIC external/glm
	PUBLIC include
)

target_link_libraries("${PROJECT_NAME}"
	log
	vulkan
	glfw
	glm
)