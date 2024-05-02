//
// Created by user on 25.04.24.
//
#include "async_server/ServerMessages.h"
#include "protobuf/parser/InterfaceProtobufMessage.h"

#include <gtest/gtest.h>

namespace
{
    std::string captureOutput(std::function<void()> func)
    {
        std::stringstream buffer;
        std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
        func();
        std::cout.rdbuf(old);
        return buffer.str();
    }
}

TEST(ServerMessages, GetIdOneTest)
{
    int digit = 1;
    ServerMessages serverMessages;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto getID = interfaceProtobufMessage.CreateMessage("GetId");
    auto serverAnsuer = serverMessages.GetServerQueshion(getID);
    InterfaceProtobufMessage interfaceProtobufMessage2;
    auto rightMessage = interfaceProtobufMessage2.CreateMessage(digit);
    ASSERT_EQ(serverAnsuer, rightMessage);
}

TEST(ServerMessages, GetIdAnyTest)
{
    int count= 10;
    std::vector<std::string> vecServerAnswer = {};
    ServerMessages serverMessages;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto getID = interfaceProtobufMessage.CreateMessage("GetId");
    for(size_t i = 0; i < count; i++)
        vecServerAnswer.push_back(serverMessages.GetServerQueshion(getID));
    for(size_t i = 0; i < count; i++)
    {
        InterfaceProtobufMessage interfaceProtobufMessage2;
        auto rightMessage = interfaceProtobufMessage2.CreateMessage((i+1));
        ASSERT_EQ(vecServerAnswer[i], rightMessage);
    }
}

TEST(ServerMessages, FaultTest)
{
    ServerMessages serverMessages;
    std::string wrongData = "\x05wrong";
    ASSERT_THROW(serverMessages.GetServerQueshion(wrongData), std::runtime_error);
}

TEST(ServerMessages, StreamOneConectedTest)
{
    ServerMessages serverMessages;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto getID = interfaceProtobufMessage.CreateMessage("GetId");
    std::string stream = captureOutput([&]()
            {serverMessages.GetServerQueshion(getID);}
            );
    EXPECT_TRUE(stream.find("connection established: 1") != std::string::npos);
}

TEST(ServerMessages, StreamAnyConectedTest)
{
    int count= 10;
    ServerMessages serverMessages;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto getID = interfaceProtobufMessage.CreateMessage("GetId");
    std::string stream = captureOutput([&]()
                                       {
                                           for(size_t i = 0; i < count; i++)
                                               serverMessages.GetServerQueshion(getID);
                                       }
    );
    for(size_t i = 0; i < count; i++)
    {
        std::string message = "connection established: " + std::to_string(i + 1);
        EXPECT_TRUE(stream.find(message) != std::string::npos);
    }
}

TEST(ServerMessages, ReturnedOneMessageTest)
{
    int digit = 1;
    ServerMessages serverMessages;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto getID = interfaceProtobufMessage.CreateMessage("GetId");
    auto serverAnsuer = serverMessages.GetServerQueshion(getID);
    InterfaceProtobufMessage interfaceProtobufMessage2;
    auto rightAnswer = interfaceProtobufMessage2.CreateMessage(digit);
    ASSERT_EQ(rightAnswer, serverAnsuer);
}

TEST(ServerMessages, ReturnedSessionMessageTest)
{
    int digit = 1;
    ServerMessages serverMessages;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto getID = interfaceProtobufMessage.CreateMessage("GetId");
    auto serverAnsuer = serverMessages.GetServerQueshion(getID);
    InterfaceProtobufMessage interfaceProtobufMessage2;
    auto rightAnswer = interfaceProtobufMessage2.CreateMessage(digit);
    ASSERT_EQ(rightAnswer, serverAnsuer);

    auto workRightAnsuer = interfaceProtobufMessage.CreateMessage("Work");
    serverAnsuer = serverMessages.GetServerQueshion(workRightAnsuer);
    ASSERT_EQ(workRightAnsuer, serverAnsuer);

    auto stop = interfaceProtobufMessage.CreateMessage("Stop");
    serverAnsuer = serverMessages.GetServerQueshion(stop);
    rightAnswer = interfaceProtobufMessage.CreateMessage();
    ASSERT_EQ(rightAnswer, serverAnsuer);
}
