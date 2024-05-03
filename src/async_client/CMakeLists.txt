set(PROJECT_NAME client)

set(HDRS
        blocking_tcp_echo_client.h
)
set(SRCS
        src/blocking_tcp_echo_client.cpp
)
add_library(lib_client OBJECT ${SRCS} ${HDRS})

find_package(Boost 1.58.0 COMPONENTS program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()