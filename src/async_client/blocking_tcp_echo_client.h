//
// Created by user on 22.03.24.
//

#ifndef ASSING_IN_OUT_BLOCKING_TCP_ECHO_CLIENT_H
#define ASSING_IN_OUT_BLOCKING_TCP_ECHO_CLIENT_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

enum { max_length = 1024 };

class Client
{
public:
    Client(std::string host, std::string port);
    std::string sendMessage(std::string);
private:
    std::string m_host;
    std::string m_port;

    boost::asio::io_context m_io_context;
    tcp::socket m_s;
    tcp::resolver m_resolver;
};

#endif //ASSING_IN_OUT_BLOCKING_TCP_ECHO_CLIENT_H
