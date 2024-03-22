set(PROJECT_NAME server)

set(HDRS
        async_tcp_echo_server.h
)
set(SRCS
        src/async_tcp_echo_server.cpp
)
add_library(lib_server OBJECT ${SRCS} ${HDRS})

find_package(Boost 1.58.0 COMPONENTS program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} async_tcp_echo_server.h main.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} lib_server)
endif()