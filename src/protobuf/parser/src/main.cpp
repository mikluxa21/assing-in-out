//
// Created by user on 12.04.24.
//

#include "protobuf/parser/DelimitedMessagesStreamParser.h"
#include "protobuf/parser/Parser.h"
#include "src/protobuf/protobuf/message.pb.h"
#include "protobuf/parser/InterfaceProtobufMessage.h"

#include <string>
#include <iostream>


int main()
{
    std::string str = "Hello world";
    std::list<typename DelimitedMessagesStreamParser<TestTask::Messages::WrapperMessage>::PointerToConstValue> messages;
    DelimitedMessagesStreamParser<TestTask::Messages::WrapperMessage> parser;

    TestTask::Messages::WrapperMessage message;
    message.mutable_fast_response()->set_message_data(str);
    auto data = serializeDelimited(message);
    std::cout << str << std::endl;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resData = interfaceProtobufMessage.CreateMessage(str);
    std::string hz = std::string(data->begin(), data->end());
    std::cout << hz.size() << resData.size() << std::endl;
    auto res = parser.parse(std::string(data->begin(), data->end()));
    for(auto i: res)
        std::cout << i->fast_response().message_data();
}