set(
		PROJECT_NAME devices
)
set(HDRS
		DeviceClient.h
		InterfaceDeviceClient.h
)

set(SRCS
		src/DeviceClient.cpp
		src/InterfaceDeviceClient.cpp
)

set(
		LIB_NAME lib_devices
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
		lib_parser
		lib_proto
		${Protobuf_LIBRARIES}
)
