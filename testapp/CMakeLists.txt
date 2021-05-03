cmake_minimum_required(VERSION 3.16.2)

project(testapp)

add_executable("${PROJECT_NAME}"
	"game.cpp"
	"testapp.h"
	"testapp.cpp"
)

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

target_include_directories("${PROJECT_NAME}"
	PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/core
	PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/log
)

target_link_libraries("${PROJECT_NAME}"
	minerva
	log
)