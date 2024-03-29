#include <vector>
#include <memory>
#include <string>
#include <google/protobuf/message.h>

#ifndef SRC_PROTOBUF_PARSER_HELPERS_H_
#define SRC_PROTOBUF_PARSER_HELPERS_H_

#if GOOGLE_PROTOBUF_VERSION >= 3012004
#define PROTOBUF_MESSAGE_BYTE_SIZE(message) ((message).ByteSizeLong())
#else
#define PROTOBUF_MESSAGE_BYTE_SIZE(message) ((message).ByteSize())
#endif
typedef std::vector<char> Data;
typedef std::shared_ptr<const Data> PointerToConstData;
typedef std::shared_ptr<Data> PointerToData;

template <class Message>
PointerToConstData serializeDelimited(const Message& msg)
{
	const size_t messageSize = PROTOBUF_MESSAGE_BYTE_SIZE(msg);
	const size_t headerSize = google::protobuf::io::CodedOutputStream::VarintSize32(messageSize);
	const PointerToData& result = std::make_shared<Data>(headerSize+messageSize);
	google::protobuf::uint8* buffer = reinterpret_cast<google::protobuf::uint8*> (&*result->begin());
	google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(messageSize, buffer);
	msg.SerializeWithCachedSizesToArray(buffer + headerSize);
	return result;
}


template <class Message>
std::shared_ptr<Message> parseDelimited(const void* data, size_t size, size_t* bytesConsumed = 0)
{
  if(data == nullptr ||  size == 0)
    return nullptr;
  google::protobuf::io::ArrayInputStream arrayInput(reinterpret_cast<const char*> (data), size);
  google::protobuf::io::CodedInputStream codedInput(&arrayInput);

  google::protobuf::uint32 messageSize;
  if(!codedInput.ReadVarint32(&messageSize))
    throw std::runtime_error("ReadVarint32 faild");
  if((codedInput.CurrentPosition() + messageSize) > size)
    return nullptr;
  auto limit = codedInput.PushLimit(messageSize);

  Message msg;
  if(!msg.ParseFromCodedStream(&codedInput))
    throw std::runtime_error("ParseFromeCodedStream faild");
  codedInput.PopLimit(limit);

  *bytesConsumed = codedInput.CurrentPosition();
  return std::make_shared<Message> (msg);
}






#endif /* SRC_PROTOBUF_PARSER_HELPERS_H_ */
