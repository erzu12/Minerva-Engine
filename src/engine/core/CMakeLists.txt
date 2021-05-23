set(ASSETS_PATH ${CMAKE_SOURCE_DIR}/assets)
message("assets dir: " ${ASSETS_PATH})

message("project dir: " ${CMAKE_CURRENT_SOURCE_DIR})

configure_file (config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h @ONLY)

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
	"scene/sceneloader.cpp"
	"scene/sceneloader.h"
	"scene/modules.h"
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