set(PROJECT_NAME protobuf)
cmake_minimum_required(VERSION 3.16.3)
cmake_policy(SET CMP0016 NEW)

find_package(Protobuf REQUIRED)
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER protobuf/message.proto)
ADD_LIBRARY(lib_proto ${PROTO_HEADER} ${PROTO_SRC})

set(HDRS
        DelimitedMessagesStreamParser.h
        Parser.h
)
set(SRCS
        src/DelimitedMessagesStreamParser.cpp
)
add_library(lib_protobuf OBJECT ${SRCS} ${HDRS})
target_link_libraries(lib_protobuf lib_proto)