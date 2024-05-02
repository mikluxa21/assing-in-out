set(PROJECT_NAME client)

set(HDRS
        blocking_tcp_echo_client.h
)
set(SRCS
        src/blocking_tcp_echo_client.cpp
        ../parallel_executor/src/ParallelclientExecutor.cpp
        ../parallel_executor/ParallelclientExecutor.h
        ../parallel_executor/src/main.cpp
)
add_library(lib_client OBJECT ${SRCS} ${HDRS})

find_package(Boost 1.58.0 COMPONENTS program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} src/main.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} lib_client)
endif()