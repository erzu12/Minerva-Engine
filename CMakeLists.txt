cmake_minimum_required(VERSION 3.17.2)

project(minerva)

add_executable("${PROJECT_NAME}" "main.cpp")

add_subdirectory(Log)

target_include_directories("${PROJECT_NAME}" PUBLIC log)

target_link_libraries("${PROJECT_NAME}" log)
