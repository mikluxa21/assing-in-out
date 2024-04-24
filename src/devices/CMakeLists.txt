set(
		PROJECT_NAME parallel_executor
)
set(HDRS
		DeviceClient.h
		DeviceServer.h
        )

set(SRCS
		src/DeviceClient.cpp
		src/DeviceServer.cpp
)

set(
		LIB_NAME devices
)
add_library(${LIB_NAME}
		OBJECT ${SRCS} ${HDRS}
)
add_executable(${PROJECT_NAME}
		src/main.cpp
)
target_link_libraries(${PROJECT_NAME}
		${LIB_NAME}
		lib_client
		lib_server
		lib_parser
		lib_proto
		${Protobuf_LIBRARIES}
)
