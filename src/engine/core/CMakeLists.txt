add_library("${PROJECT_NAME}"
	"window/window.cpp"
	"window/window.h"
	"events/events.h"
	"events/inputEvents.h"
	"events/appEvents.h"
	"scene/scene.cpp"
	"scene/scene.h"
	"scene/object.cpp"
	"scene/object.h"
	"scene/mesh.cpp"
	"scene/mesh.h"
	"init.cpp"
	"run.cpp"
	"${CMAKE_SOURCE_DIR}/include/minerva.h"
)

target_include_directories("${PROJECT_NAME}"
	PUBLIC events
)

