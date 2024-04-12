//
// Created by user on 12.04.24.
//

#ifndef ASYNC_INTERFACEPROTOBUFMESSAGE_H
#define ASYNC_INTERFACEPROTOBUFMESSAGE_H

#include "protobuf/parser/DelimitedMessagesStreamParser.h"
#include "protobuf/parser/Parser.h"
#include "protobuf/protobuf/message.pb.h"

#include <string>
#include <map>

class InterfaceProtobufMessage {
public:
    InterfaceProtobufMessage();
    std::string CreateMessage();
    std::string CreateMessage(int);
    std::string CreateMessage(std::string);

    std::map<std::string, std::string> ParseMessage(std::string);

private:
    TestTask::Messages::WrapperMessage m_message;

};


#endif //ASYNC_INTERFACEPROTOBUFMESSAGE_H
