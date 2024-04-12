//
// blocking_tcp_echo_client.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "async_client/blocking_tcp_echo_client.h"


Client::Client(std::string host, std::string port)
                : m_host(std::move(host)), m_port(std::move(port)),
                    m_s(std::move(tcp::socket(m_io_context))), m_resolver(std::move(tcp::resolver(m_io_context)))
{
    try{
        boost::asio::connect(this->m_s, this->m_resolver.resolve(this->m_host.c_str(), this->m_port.c_str()));
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

std::string Client::sendMessage(std::string message) {
    char reply[max_length];
    size_t reply_length;
    try{
        boost::asio::write(this->m_s, boost::asio::buffer(message.c_str(), message.length()));
        reply_length = boost::asio::read(this->m_s, boost::asio::buffer(reply, message.length()));
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return std::string(reply);
}

/*void Client::runWork() {
    try
    {
    boost::asio::io_context io_context;

    tcp::socket s(io_context);
    tcp::resolver resolver(io_context);
    boost::asio::connect(s, resolver.resolve(this->m_host.c_str(), this->m_port.c_str()));
    for(size_t i = 0; i < 2; i++)
        {
            std::cout << "Enter message: ";
            char request[max_length];
            std::cin.getline(request, max_length);
            size_t request_length = std::strlen(request);
            boost::asio::write(s, boost::asio::buffer(request, request_length));

            char reply[max_length];
            size_t reply_length = boost::asio::read(s,
                                                    boost::asio::buffer(reply, request_length));
            std::cout << "Reply is: ";
            std::cout.write(reply, reply_length);
            std::cout << "\n";
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}*/
