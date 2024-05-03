set(
        PROJECT_NAME parallel_executor
)
set(HDRS
        ParallelClientExecutor.h
)

set(SRCS
        src/ParallelClientExecutor.cpp
)

set(
        LIB_NAME lib_parallel_executor
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
        lib_devices
)
