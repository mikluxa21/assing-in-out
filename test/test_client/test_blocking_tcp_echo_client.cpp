#include "client/blocking_tcp_echo_client.h"

#include <gtest/gtest.h>


TEST(Client, defaultInitCrushNotFoundServerTest)
{
    std::string port{"None"};
    std::string host{"None"};
   EXPECT_THROW(Client client(port, host), std::runtime_error);
}

TEST(Client, defaultErrorSendingMessage)
{
    std::string port{"127.0.0.1"};
    std::string host{"8080"};
    Client client(port, host);
   EXPECT_THROW(client.sendMessage("None"), std::runtime_error);
}
