//
// Created by user on 22.03.24.
//
#include "async_client/blocking_tcp_echo_client.h"

int main(int argc, char* argv[])
{
    auto* client = new Client();
    std::string message = "Hello world";
    std::cout << client->sendMessage(message);
    delete client;
    return 0;
}