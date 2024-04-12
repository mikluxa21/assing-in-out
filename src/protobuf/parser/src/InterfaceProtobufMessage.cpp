//
// Created by user on 12.04.24.
//

#include "protobuf/parser/InterfaceProtobufMessage.h"


InterfaceProtobufMessage::InterfaceProtobufMessage() {
    this->m_message.mutable_request_for_fast_response();
}

std::string InterfaceProtobufMessage::CreateMessage() {
    auto resMessage = serializeDelimited(this->m_message);
    return resMessage->data();
}

std::string InterfaceProtobufMessage::CreateMessage(int message) {
    this->m_message.mutable_slow_response()->set_client_id(message);
    auto resMessage = serializeDelimited(this->m_message);
    return resMessage->data();
}

std::string InterfaceProtobufMessage::CreateMessage(std::string message) {
    this->m_message.mutable_fast_response()->set_message_data(message);
    auto resMessage = serializeDelimited(this->m_message);
    return resMessage->data();
}

std::map<std::string, std::string> InterfaceProtobufMessage::ParseMessage(std::string message) {
    DelimitedMessagesStreamParser<TestTask::Messages::WrapperMessage> parser;
    std::map<std::string, std::string> resultMap;
    auto parseRes = *parser.parse(message).begin();
    if(parseRes->has_request_for_fast_response())
        resultMap["request_for_fast_response"] = "";
    else
        resultMap["request_for_fast_response"] = nullptr;
    if(parseRes->has_fast_response())
        resultMap["message_data"] = parseRes->fast_response().message_data();
    else
        resultMap["message_data"] = nullptr;
    if(parseRes->has_slow_response())
        resultMap["client_id"] = parseRes->slow_response().client_id();
    else
        resultMap["client_id"] = nullptr;
    return resultMap;
}
