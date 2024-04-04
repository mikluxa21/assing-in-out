set(
		PROJECT_NAME parallel_executor
)
set(HDRS
		Device.h
		DeviceClient.h
        )

set(SRCS
         )

set(
		LIB_NAME parall_lib
)
add_library(${LIB_NAME} OBJECT ${SRCS} ${HDRS})

find_package(Boost 1.58.0 COMPONENTS filesystem program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} src/main.cpp)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()
target_link_libraries(${PROJECT_NAME} ${LIB_NAME})
