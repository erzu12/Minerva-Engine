add_library(vulkan "vulkan.cpp" "vulkan.h")

find_package(Vulkan REQUIRED FATAL_ERROR)

set_property(TARGET vulkan PROPERTY CXX_STANDARD 17)

target_include_directories(vulkan
	PUBLIC ${Vulkan_INCLUDE_DIRS}
	PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/core
	PUBLIC ${CMAKE_SOURCE_DIR}/external/stb
	PUBLIC ${CMAKE_SOURCE_DIR}/external/tinyobjloader
)

target_link_libraries(vulkan
	glm
	glfw
	${Vulkan_LIBRARIES}
)