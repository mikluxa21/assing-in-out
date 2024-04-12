//
// Created by user on 14.03.24.
//
#include "async_server/async_tcp_echo_server.h"

#include "async_server/async_tcp_echo_server.h"

#include <gtest/gtest.h>
short port = 8080;

TEST(ServerTests, EmptyTest)
{
    boost::asio::io_context io_context;

    server s(io_context, port);

    io_context.run();

}