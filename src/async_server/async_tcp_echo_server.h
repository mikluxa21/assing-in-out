#ifndef ASSING_IN_OUT_ASYNC_TCP_ECHO_SERVER_H
#define ASSING_IN_OUT_ASYNC_TCP_ECHO_SERVER_H

#include "async_server/ServerMessages.h"

#include <iostream>
#include <memory>
#include <utility>

#include <boost/asio.hpp>



using boost::asio::ip::tcp;

class session
        : public std::enable_shared_from_this<session>
{
public:
    explicit session(tcp::socket socket);

    void start();

private:
    void do_read();

    void do_write(std::size_t length);

    tcp::socket socket_;
    enum { max_length = 1024 };
    char m_data[max_length];
    ServerMessages m_serverMessages;
};

class server
{
public:
    server(boost::asio::io_context& io_context, short port);

private:
    void do_accept();

    tcp::acceptor acceptor_;
};

class worker
{
public:
    void run(int host = 8080);
};

#endif //ASSING_IN_OUT_ASYNC_TCP_ECHO_SERVER_H