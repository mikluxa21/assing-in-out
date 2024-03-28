//
// Created by user on 22.03.24.
//
#include "async_server/async_tcp_echo_server.h"
int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: async_tcp_echo_server <port>\n" << argc << argv[1];
            return 1;
        }
        std::cerr << "Tests  " << argc << std::endl << argv[1] << std::endl;

        boost::asio::io_context io_context;

        server s(io_context, std::atoi(argv[1]));

        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}