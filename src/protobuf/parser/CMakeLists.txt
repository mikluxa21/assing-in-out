set(PROJECT_NAME protobuf_parser)
set(HDRS
        DelimitedMessagesStreamParser.h
)
set(SRCS
        src/DelimitedMessagesStreamParser.cpp
)

add_library(lib_protobuf OBJECT ${SRCS} ${HDRS})