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
    explicit Client(std::string host = "127.0.0.1", std::string port = "8080");
private:
    void runWork();
private:
    std::string m_host;
    std::string m_port;
};

#endif //ASSING_IN_OUT_BLOCKING_TCP_ECHO_CLIENT_H
