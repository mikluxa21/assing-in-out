//
// async_tcp_echo_server.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef ASSING_IN_OUT_ASYNC_TCP_ECHO_SERVER_H
#define ASSING_IN_OUT_ASYNC_TCP_ECHO_SERVER_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class session
        : public std::enable_shared_from_this<session>
{
public:
    explicit session(tcp::socket socket)
            : socket_(std::move(socket))
    {}

    void start();

private:
    void do_read();

    void do_write(std::size_t length);

    tcp::socket socket_;
    enum { max_length = 1024 };
    char m_data[max_length];
};

class server
{
public:
    server(boost::asio::io_context& io_context, short port);

private:
    void do_accept();

    tcp::acceptor acceptor_;
};

#endif //ASSING_IN_OUT_ASYNC_TCP_ECHO_SERVER_H