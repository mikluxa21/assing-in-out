set(
		PROJECT_NAME parallel_executor
)
set(HDRS
		DeviceClient.h
        )

set(SRCS
        src/DeviceClient.cpp
         )

set(
		LIB_NAME parall_lib
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
)
