add_executable("${PROJECT_NAME}"
	"main.cpp"
	"window/window.cpp"
	"window/window.h"
	"events/events.h"
	"events/inputEvents.h"
	"events/appEvents.h"
)

target_include_directories("${PROJECT_NAME}"
	PUBLIC events
)