//
// Created by user on 22.03.24.
//
#include "async_client/blocking_tcp_echo_client.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
        return 1;
    }
    auto* client = new Client();
    delete client;
    return 0;
}