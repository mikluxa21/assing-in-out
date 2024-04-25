set(PROJECT_NAME server)

set(HDRS
        async_tcp_echo_server.h
        ServerMessages.h
)
set(SRCS
        src/async_tcp_echo_server.cpp
        src/ServerMessages.cpp
)
add_library(lib_server OBJECT ${SRCS} ${HDRS})

find_package(Boost 1.58.0 COMPONENTS program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME}  src/main.cpp)
    target_link_libraries(${PROJECT_NAME}
            ${Boost_LIBRARIES}
            lib_server
            lib_parser
            lib_proto
            ${Protobuf_LIBRARIES}
    )
endif()