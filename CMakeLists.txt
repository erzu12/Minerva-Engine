cmake_minimum_required(VERSION 3.16.2)

project(minerva)

add_subdirectory(src/engine)
add_subdirectory(src/editor)
add_subdirectory(testapp)

add_subdirectory(external/glfw)
add_subdirectory(external/glm)

find_package(Vulkan REQUIRED FATAL_ERROR)

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)


target_include_directories("${PROJECT_NAME}"
	PUBLIC include
)
