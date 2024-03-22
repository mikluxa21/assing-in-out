cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)
set(CMAKE_CXX_STANDART 11)
project(server VERSION 1.0.0 DESCRIPTION "TCP echo server")

find_package(Boost 1.58.0 COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} async_tcp_echo_server.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()