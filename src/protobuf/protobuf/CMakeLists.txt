#set(PROJECT_NAME protobuf_message)
protobuf_generate_cpp(PROTO_SRC PROTO_HEADER message.proto)
#add_library(lib_proto ${PROTO_SRC} ${PROTO_HEADER})