add_library("${PROJECT_NAME}"
	"minerva.cpp"
	"minerva.h"
	"window/window.cpp"
	"window/window.h"
	"events/events.h"
	"events/inputEvents.h"
	"events/appEvents.h"
	"scene/scene.cpp"
	"scene/scene.h"
	"scene/object.cpp"
	"scene/object.h"
	"scene/module.cpp"
	"scene/module.h"
	"scene/mesh.cpp"
	"scene/mesh.h"
	"scene/meshloader.cpp"
	"scene/meshloader.h"
	"scene/sceneloader.cpp"
	"scene/sceneloader.h"
)

target_include_directories("${PROJECT_NAME}"
	PUBLIC .
	PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/log
	PUBLIC ${CMAKE_SOURCE_DIR}/src/engine/vulkan
	PUBLIC ${CMAKE_SOURCE_DIR}/external/glfw/inculde
)


target_link_libraries("${PROJECT_NAME}"
	log
	vulkan
	glfw
)