cmake_minimum_required(VERSION 3.17.2)

project(testapp)

add_executable("${PROJECT_NAME}"
	"testapp.cpp"
)

target_include_directories("${PROJECT_NAME}"
	PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries("${PROJECT_NAME}"
	minerva
)