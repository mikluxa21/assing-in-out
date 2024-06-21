#include "async_server/async_tcp_echo_server.h"

session::session(tcp::socket socket)
        : socket_(std::move(socket))
{}

void session::start(size_t sessionId)
{
    this->m_sessionId = sessionId;
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
                                    do_write(length);
                                }
                                this->async_receive(ec);
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

void session::async_receive(boost::system::error_code const& error)
  {
    if ((boost::asio::error::eof == error) ||
        (boost::asio::error::connection_reset == error))
    {
      std::cout << "connection lost: " << this->m_sessionId << std::endl;
    }
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
                    std::make_shared<session>(std::move(socket))->start(this->m_clientCounter);
                    std::cout << "connection established: " << this->m_clientCounter++ << std::endl;
                }

                do_accept();
            });
}

void worker::run(int host)
{
    try
    {
        boost::asio::io_context io_context;

        server s(io_context, host);

        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
