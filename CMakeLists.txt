cmake_minimum_required(VERSION 3.15.0)
project(async VERSION 1.0.0 DESCRIPTION "Знакомство с асинхронным вводом/выводом на C++")
cmake_policy(SET CMP0016 NEW)
set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/protobuf/protobuf)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Protobuf_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/async_client)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/async_server)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/protobuf/parser)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/devices)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/parallel_executor)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/main)

enable_testing()
add_subdirectory(test)
