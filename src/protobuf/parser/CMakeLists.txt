set(PROJECT_NAME protobuf_parser)
set(HDRS
        DelimitedMessagesStreamParser.h
        Parser.h
)
set(SRCS
        src/DelimitedMessagesStreamParser.cpp
)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME}
        lib_protobuf
        ${Protobuf_LIBRARIES}
        lib_proto
)
add_library(lib_protobuf OBJECT ${SRCS} ${HDRS})