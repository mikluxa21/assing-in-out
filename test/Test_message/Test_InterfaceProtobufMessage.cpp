//
// Created by mikluxa on 23.04.24.
//

#include "protobuf/parser/InterfaceProtobufMessage.h"
#include "protobuf/parser/DelimitedMessagesStreamParser.h"

#include <gtest/gtest.h>

TEST(InterfaceProtobufMessage, EmptyTest)
{
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto res = interfaceProtobufMessage.GetMessage();
    ASSERT_TRUE(res.has_request_for_fast_response());
}

TEST(InterfaceProtobufMessage, EmptyCreateTest)
{
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto res = interfaceProtobufMessage.CreateMessage();
    ASSERT_EQ(res.size(), 2);
}

TEST(InterfaceProtobufMessage, IntCreateTest)
{
    int digit = 10;

    TestTask::Messages::WrapperMessage message;
    message.mutable_request_for_fast_response();
    message.mutable_slow_response()->set_client_id(digit);
    auto rightMess =  serializeDelimited(message);

    InterfaceProtobufMessage interfaceProtobufMessage;
    auto res = interfaceProtobufMessage.CreateMessage(digit);

    ASSERT_EQ(res.size(), std::string(rightMess->data()).size());
    ASSERT_EQ(res, std::string (rightMess->data()));
}

TEST(InterfaceProtobufMessage, StringCreateTest)
{
    std::string str{"Hello world"};
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto res = interfaceProtobufMessage.CreateMessage(str);
    ASSERT_EQ(res.size(), 17);
}

TEST(InterfaceProtobufMessage, ParseMessageFastResoponseTest)
{
    TestTask::Messages::WrapperMessage message;
    message.mutable_request_for_fast_response();
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto res = interfaceProtobufMessage.ParseMessage(std::string(resMessage->begin(), resMessage->end()));
    ASSERT_EQ(res["request_for_fast_response"], "1");
    ASSERT_EQ(res["message_data"], "");
    ASSERT_EQ(res["client_id"], "");
}

TEST(InterfaceProtobufMessage, ParseMessageDataTest)
{
    TestTask::Messages::WrapperMessage message;
    message.mutable_fast_response()->set_message_data("Hello world!");
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto res = interfaceProtobufMessage.ParseMessage(std::string(resMessage->begin(), resMessage->end()));
    ASSERT_EQ(res["request_for_fast_response"], "");
    ASSERT_EQ(res["message_data"], "Hello world!");
    ASSERT_EQ(res["client_id"], "");
}

TEST(InterfaceProtobufMessage, ParseMessageClientIdTest)
{
    TestTask::Messages::WrapperMessage message;
    message.mutable_slow_response()->set_client_id(12);
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto res = interfaceProtobufMessage.ParseMessage(std::string(resMessage->begin(), resMessage->end()));
    ASSERT_EQ(res["request_for_fast_response"], "");
    ASSERT_EQ(res["message_data"], "");
    ASSERT_EQ(atoi(res["client_id"].c_str()), 12);
}

TEST(InterfaceProtobufMessage, ParseMessageAllPlaceTest)
{
    TestTask::Messages::WrapperMessage message;
    message.mutable_request_for_fast_response();
    message.mutable_fast_response()->set_message_data("Hello world!");
    message.mutable_slow_response()->set_client_id(12);
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto res = interfaceProtobufMessage.ParseMessage(std::string(resMessage->begin(), resMessage->end()));
    ASSERT_EQ(res["request_for_fast_response"], "1");
    ASSERT_EQ(res["message_data"], "Hello world!");
    ASSERT_EQ(atoi(res["client_id"].c_str()), 12);
}

TEST(InterfaceProtobufMessage, ParseMessageEmtyTest)
{
    TestTask::Messages::WrapperMessage message;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto res = interfaceProtobufMessage.ParseMessage(std::string(resMessage->begin(), resMessage->end()));
    ASSERT_EQ(res["request_for_fast_response"], "");
    ASSERT_EQ(res["message_data"], "");
    ASSERT_EQ(res["client_id"], "");
}

TEST(InterfaceProtobufMessage, ComplexIntagrationTest)
{
    int digit = 10;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto digitMessage = interfaceProtobufMessage.CreateMessage(digit);
    auto resParsing = interfaceProtobufMessage.ParseMessage(std::string(digitMessage));
    auto returnDigit = atoi(resParsing["client_id"].c_str());
    ASSERT_EQ(digit, returnDigit);

}