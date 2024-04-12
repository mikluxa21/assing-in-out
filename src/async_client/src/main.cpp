//
// Created by user on 22.03.24.
//
#include "async_client/blocking_tcp_echo_client.h"

int main(int argc, char* argv[])
{
    auto client =  Client("127.0.0.1", "8080");
    std::string message = "Hello world";
    std::cout << client.sendMessage(message);
    return 0;
}