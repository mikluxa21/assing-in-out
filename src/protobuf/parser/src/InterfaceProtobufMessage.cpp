//
// Created by user on 12.04.24.
//

#include "protobuf/parser/InterfaceProtobufMessage.h"


InterfaceProtobufMessage::InterfaceProtobufMessage() {
    this->m_message.mutable_request_for_fast_response();
}

std::string InterfaceProtobufMessage::CreateMessage() {
    auto resMessage = serializeDelimited(this->m_message);
    return std::string(resMessage->begin(), resMessage->end());
}

std::string InterfaceProtobufMessage::CreateMessage(int message) {
    this->m_message.mutable_slow_response()->set_client_id(message);
    auto resMessage = serializeDelimited(this->m_message);
    return std::string(resMessage->begin(), resMessage->end());
}

std::string InterfaceProtobufMessage::CreateMessage(const std::string& message) {
    this->m_message.mutable_fast_response()->set_message_data(message);
    auto resMessage = serializeDelimited(this->m_message);
    return std::string(resMessage->begin(), resMessage->end());
}

std::map<std::string, std::string> InterfaceProtobufMessage::ParseMessage(std::string& message) {
    if((int) message[message.size() - 1] != 0) //When transferring data, the last element is lost
    {
        char lastElement = 0;
        message += std::string(1, lastElement);
    }
    DelimitedMessagesStreamParser<TestTask::Messages::WrapperMessage> parser;
    std::map<std::string, std::string> resultMap
            {
                    {"request_for_fast_response", ""},
                    {"message_data", ""},
                    {"client_id", ""}
            };
    auto parse = parser.parse(message);

    if(parse.empty())
        throw std::runtime_error("InterfaceProtobufMessage::ParseMessage: Error in the parsing");

    auto parseRes = parse.front();
    if(parseRes->has_request_for_fast_response())
        resultMap["request_for_fast_response"] = "1";
    if(parseRes->has_fast_response())
        resultMap["message_data"] = parseRes->fast_response().message_data();
    if(parseRes->has_slow_response())
    {
        resultMap["client_id"] = std::to_string(parseRes->slow_response().client_id());
        this->m_message.mutable_slow_response()->set_client_id(stoi(resultMap["client_id"]));
    }
    return resultMap;
}

TestTask::Messages::WrapperMessage& InterfaceProtobufMessage::GetMessage() {
    return this->m_message;
}
