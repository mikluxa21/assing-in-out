set(
		PROJECT_NAME parallel_executor
)
set(HDRS
	Device.h
	DeviceA.h
	DeviceB.h
	DeviceEvent.h
	Parser.h
	StartedEvent.h
	WorkDoneEvent.h
	DataEvent.h
	Event.h
	EventQueue.h
        )

set(SRCS
	src/Device.cpp
	src/DeviceA.cpp
	src/DeviceB.cpp
	src/DeviceEvent.cpp
	src/Parser.cpp
	src/StartedEvent.cpp
	src/WorkDoneEvent.cpp
	src/DataEvent.cpp
	src/Event.cpp
	src/EventQueue.cpp
         )

set(
		LIB_NAME parall_lib
)
add_library(${LIB_NAME} OBJECT ${SRCS} ${HDRS})

find_package(Boost 1.58.0 COMPONENTS filesystem program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} src/main.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()
target_link_libraries(${PROJECT_NAME} ${LIB_NAME})
