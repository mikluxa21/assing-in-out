//
// Created by user on 22.03.24.
//
#include "async_server/async_tcp_echo_server.h"

session::session(tcp::socket socket)
        : socket_(std::move(socket))
{}

void session::start()
{
    do_read();
}

void session::do_read()
{
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(m_data, max_length),
                            [this, self](boost::system::error_code ec, std::size_t length)
                            {

                                if (!ec)
                                {
                                    std::string getedData = std::string(m_data);
                                    std::string serverAnswer = m_serverMessages.GetServerQueshion(getedData);
                                    std::strcpy(m_data, serverAnswer.c_str());
                                    do_write(length);
                                }
                            });
}

void session::do_write(std::size_t length)
{
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(m_data, length),
                             [this, self](boost::system::error_code ec, std::size_t /*length*/)
                             {
                                 if (!ec)
                                 {
                                     do_read();
                                 }
                             });
}

server::server(boost::asio::io_context &io_context, short port = 80)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
{
    do_accept();
}

void server::do_accept()
{
    acceptor_.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket)
            {
                if (!ec)
                {
                    std::make_shared<session>(std::move(socket))->start();
                }

                do_accept();
            });
}

