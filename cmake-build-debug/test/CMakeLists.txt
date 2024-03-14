cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)

project(parallel_executor VERSION 1.0.0 DESCRIPTION "Tests for project")

include_directories(${GTEST_INCLUDE_DIRS})
find_package(GTest REQUIRED)
set(TEST_NAME executor_test)

add_executable(${TEST_NAME}
        #current .cpp files
)
add_test(NAME ${TEST_NAME}
        COMMAND ${TEST_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${TEST_NAME}
        gtest
        gtest_main
        pthread
        #lib for test
)