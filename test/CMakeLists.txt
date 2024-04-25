cmake_minimum_required(VERSION 3.15.0)
cmake_policy(SET CMP0016 NEW)

project(tests VERSION 1.0.0 DESCRIPTION "Tests for project")

include_directories(${GTEST_INCLUDE_DIRS})
find_package(GTest REQUIRED)
set(TEST_NAME executor_test)

add_executable(${TEST_NAME}
        #Test_server/Test_async_tcp_echo_server.cpp
        #Test_client/Test_blocking_tcp_echo_client.cpp
        Test_message/Test_DelimitedMessagesStreamParser.cpp
        Test_message/Test_Parser.cpp
        Test_message/Test_InterfaceProtobufMessage.cpp
        Test_server/Test_ServerMessages.cpp
        Test_server/Test_ServerMessages.cpp
        #Test_parallel/Test_DeviceClient.cpp
)
add_test(NAME ${TEST_NAME}
        COMMAND ${TEST_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${TEST_NAME}
        gtest
        gtest_main
        pthread
        lib_client
        lib_server
        lib_parser
        lib_proto
        ${Protobuf_LIBRARIES}
        lib_devices
)