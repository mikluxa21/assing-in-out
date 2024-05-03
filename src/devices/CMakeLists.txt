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