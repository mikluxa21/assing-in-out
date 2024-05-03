set(PROJECT_NAME
        protobuf_parser
)

set(LIB_NAME
        lib_parser
)
set(HDRS
        InterfaceProtobufMessage.h
        DelimitedMessagesStreamParser.h
        Parser.h
)
set(SRCS
        src/DelimitedMessagesStreamParser.cpp
        src/InterfaceProtobufMessage.cpp
)
add_library(${LIB_NAME} OBJECT ${SRCS} ${HDRS})