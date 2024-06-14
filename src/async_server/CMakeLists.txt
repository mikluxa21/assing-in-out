set(PROJECT_NAME
        server
)

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
)

include_directories(
        ${CMAKE_SOURCE_DIR}/src
)

set(HDRS
        async_tcp_echo_server.h
)
set(SRCS
        src/async_tcp_echo_server.cpp
)
set(LIB_NAME
        lib_server
)
add_library(${LIB_NAME}
        OBJECT ${SRCS} ${HDRS}
)

find_package(Boost COMPONENTS program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME}
            src/main_server.cpp
            InterfaceServer.h
            src/InterfaceServer.cpp
    )

    target_link_libraries(${PROJECT_NAME}
            ${Boost_LIBRARIES}
            ${LIB_NAME}
    )
endif()
