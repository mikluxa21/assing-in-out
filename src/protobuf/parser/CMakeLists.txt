set(PROJECT_NAME
        protobuf_parser
)

set(LIB_NAME
        lib_parser
)
set(HDRS
        Parser.h
        InterfaceProtobufMessage.h
        DelimitedMessagesStreamParser.h
)
set(SRCS
        src/InterfaceProtobufMessage.cpp
)
add_library(${LIB_NAME}
        OBJECT ${SRCS} ${HDRS}
)