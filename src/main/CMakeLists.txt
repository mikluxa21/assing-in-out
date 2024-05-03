set(
        PROJECT_NAME main
)
set(HDRS
        MainInterface.h
)

set(SRCS
        src/MainInterface.cpp
)

set(
        LIB_NAME lib_main_interface
)
add_library(${LIB_NAME}
        OBJECT ${SRCS} ${HDRS}
)

find_package(Boost 1.58.0 COMPONENTS filesystem program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} src/main.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

target_link_libraries(${PROJECT_NAME}
        ${LIB_NAME}
        lib_client
        lib_server
        lib_parser
        lib_proto
        ${Protobuf_LIBRARIES}
        lib_devices
        lib_parallel_executor
)