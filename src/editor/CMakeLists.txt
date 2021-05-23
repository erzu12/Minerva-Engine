cmake_minimum_required(VERSION 3.16.2)

project(minerva_editor)

add_executable("${PROJECT_NAME}"
	"editor.cpp"
	"scene_creator.h"
	"scene_creator.cpp"
	"scene_saver.h"
	"scene_saver.cpp"
	"mesh_loader.h"
	"mesh_loader.cpp"
	"modules.h"
	"modules.cpp"
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