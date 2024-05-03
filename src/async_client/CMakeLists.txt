set(
        PROJECT_NAME client
)
set(HDRS
        blocking_tcp_echo_client.h
)
set(SRCS
        src/blocking_tcp_echo_client.cpp
)
set(
        LIB_NAME lib_client
)
add_library(${LIB_NAME}
        OBJECT ${SRCS} ${HDRS}
)

find_package(Boost 1.58.0 COMPONENTS program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} src/main_client.cpp Interface.h src/Interface.cpp)

    target_link_libraries(${PROJECT_NAME}
            ${Boost_LIBRARIES}
            ${LIB_NAME}
            lib_parser
            lib_proto
            ${Protobuf_LIBRARIES}
            lib_devices
            lib_parallel_executor
    )
endif()