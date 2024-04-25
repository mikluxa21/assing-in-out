//
// Created by user on 25.04.24.
//
#include "async_server/ServerMessages.h"
#include "protobuf/parser/InterfaceProtobufMessage.h"

#include <gtest/gtest.h>

TEST(ServerMessages, GetIdTest)
{
    int digit = 0;
    ServerMessages serverMessages;
    InterfaceProtobufMessage interfaceProtobufMessage;
    auto getID = interfaceProtobufMessage.CreateMessage("GetId");
    auto serverAnsuer = serverMessages.GetServerQueshion(getID);
    auto rightMessage = interfaceProtobufMessage.CreateMessage(digit);
    ASSERT_EQ(serverAnsuer, rightMessage);
}