#ifndef ASYNC_INTERFACEPROTOBUFMESSAGE_H
#define ASYNC_INTERFACEPROTOBUFMESSAGE_H

#include "src/protobuf/protobuf/message.pb.h"
#include "protobuf/parser/DelimitedMessagesStreamParser.h"

#include <map>
#include <string>

class InterfaceProtobufMessage {
public:
    InterfaceProtobufMessage();
    std::string CreateMessage();
    std::string CreateMessage(int);
    std::string CreateMessage(const std::string&);

    void SetClientId(int);

    std::map<std::string, std::string> ParseMessage(std::string&);
private:
    TestTask::Messages::WrapperMessage m_message;
};

#endif //ASYNC_INTERFACEPROTOBUFMESSAGE_H
