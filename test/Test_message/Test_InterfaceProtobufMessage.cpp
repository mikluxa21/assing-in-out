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
    ASSERT_EQ(res.size(), 3);
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
    std::string strRes = std::string(rightMess->begin(), rightMess->end());

    ASSERT_EQ(res.size(), strRes.size());
    ASSERT_EQ(res, strRes);
}

TEST(InterfaceProtobufMessage, StringCreateTest)
{
    std::string str{"Hello world"};
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto res = interfaceProtobufMessage.CreateMessage(str);
    ASSERT_EQ(res.size(), 18);
}

TEST(InterfaceProtobufMessage, ParseMessageFastResoponseTest)
{
    TestTask::Messages::WrapperMessage message;
    message.mutable_request_for_fast_response();
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto resMessageStr = std::string(resMessage->begin(), resMessage->end());
    auto res = interfaceProtobufMessage.ParseMessage(resMessageStr);
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
    auto resMessageStr = std::string(resMessage->begin(), resMessage->end());
    auto res = interfaceProtobufMessage.ParseMessage(resMessageStr);
    ASSERT_EQ(res["request_for_fast_response"], "");
    ASSERT_EQ(res["message_data"], "Hello world!");
    ASSERT_EQ(res["client_id"], "");
}

TEST(InterfaceProtobufMessage, ParseMessageClientIdTest)
{
    int digit = 12;
    TestTask::Messages::WrapperMessage message;
    message.mutable_request_for_fast_response();
    message.mutable_slow_response()->set_client_id(digit);
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto resMessageStr = std::string(resMessage->begin(), resMessage->end());
    auto res = interfaceProtobufMessage.ParseMessage(resMessageStr);
    ASSERT_EQ(res["request_for_fast_response"], "1");
    ASSERT_EQ(res["message_data"], "");
    ASSERT_EQ(atoi(res["client_id"].c_str()), digit);
}

TEST(InterfaceProtobufMessage, ParseMessageAllPlaceTest)
{
    TestTask::Messages::WrapperMessage message;
    message.mutable_request_for_fast_response();
    message.mutable_fast_response()->set_message_data("Hello world!");
    message.mutable_slow_response()->set_client_id(12);
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto resMessageStr = std::string(resMessage->begin(), resMessage->end());
    auto res = interfaceProtobufMessage.ParseMessage(resMessageStr);
    ASSERT_EQ(res["request_for_fast_response"], "1");
    ASSERT_EQ(res["message_data"], "Hello world!");
    ASSERT_EQ(atoi(res["client_id"].c_str()), 12);
}

TEST(InterfaceProtobufMessage, ParseMessageEmtyTest)
{
    TestTask::Messages::WrapperMessage message;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto resMessage = serializeDelimited(message);
    auto resMessageStr = std::string(resMessage->begin(), resMessage->end());
    auto res = interfaceProtobufMessage.ParseMessage(resMessageStr);
    ASSERT_EQ(res["request_for_fast_response"], "");
    ASSERT_EQ(res["message_data"], "");
    ASSERT_EQ(res["client_id"], "");
}

TEST(InterfaceProtobufMessage, IntIntagrationTest)
{
    int digit = 10;
    InterfaceProtobufMessage interfaceProtobufMessage;
    std::string digitMessage = interfaceProtobufMessage.CreateMessage(digit);
    auto resParsing = interfaceProtobufMessage.ParseMessage(digitMessage);
    auto returnDigit = atoi(resParsing["client_id"].c_str());
    ASSERT_EQ(digit, returnDigit);
}

TEST(InterfaceProtobufMessage, StringIntagrationTest)
{
    std::string messageData = "Hello world!";
    InterfaceProtobufMessage interfaceProtobufMessage;
    std::string dataMessage = interfaceProtobufMessage.CreateMessage(messageData);
    auto resParsing = interfaceProtobufMessage.ParseMessage(dataMessage);
    ASSERT_EQ(resParsing["message_data"], messageData);
}

TEST(InterfaceProtobufMessage, FastResponceIntagrationTest)
{
    InterfaceProtobufMessage interfaceProtobufMessage;
    std::string dataMessage = interfaceProtobufMessage.CreateMessage();
    auto resParsing = interfaceProtobufMessage.ParseMessage(dataMessage);
    ASSERT_EQ(resParsing["request_for_fast_response"], "1");
}

TEST(InterfaceProtobufMessage, IntStringIntagrationTest)
{
    int digit = 10;
    std::string messageData = "Hello world!";
    InterfaceProtobufMessage interfaceProtobufMessage;
    std::string dataMessage = interfaceProtobufMessage.CreateMessage(messageData);
    auto resParsing = interfaceProtobufMessage.ParseMessage(dataMessage);
    ASSERT_EQ(resParsing["message_data"], messageData);

    std::string intDataMessage = interfaceProtobufMessage.CreateMessage(digit);
    resParsing = interfaceProtobufMessage.ParseMessage(intDataMessage);
    auto returnDigit = atoi(resParsing["client_id"].c_str());
    ASSERT_EQ(digit, returnDigit);
    ASSERT_EQ(resParsing["message_data"], messageData);
}

TEST(InterfaceProtobufMessage, ComplexIntagrationTest)
{
    int digit = 10;
    std::string messageData = "Hello world!";
    InterfaceProtobufMessage interfaceProtobufMessage;
    std::string dataMessage = interfaceProtobufMessage.CreateMessage(messageData);
    auto resParsing = interfaceProtobufMessage.ParseMessage(dataMessage);
    ASSERT_EQ(resParsing["message_data"], messageData);

    std::string intDataMessage = interfaceProtobufMessage.CreateMessage(digit);
    resParsing = interfaceProtobufMessage.ParseMessage(intDataMessage);
    auto returnDigit = atoi(resParsing["client_id"].c_str());
    ASSERT_EQ(digit, returnDigit);
    ASSERT_EQ(resParsing["message_data"], messageData);

    std::string complexMessage = interfaceProtobufMessage.CreateMessage();
    resParsing = interfaceProtobufMessage.ParseMessage(intDataMessage);
    ASSERT_EQ(resParsing["request_for_fast_response"], "1");
    ASSERT_EQ(digit, returnDigit);
    ASSERT_EQ(resParsing["message_data"], messageData);
}

TEST(InterfaceProtobufMessage, ThrowParseTest)
{
    InterfaceProtobufMessage interfaceProtobufMessage;
    std::string wrongMessage = "\x05wrong";
    ASSERT_THROW(interfaceProtobufMessage.ParseMessage(wrongMessage), std::runtime_error);
}
