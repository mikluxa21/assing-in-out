#include "client/blocking_tcp_echo_client.h"

Client::Client(std::string host, std::string port)
                : m_host(std::move(host)), m_port(std::move(port)),
                    m_s(std::move(tcp::socket(m_io_context))), m_resolver(std::move(tcp::resolver(m_io_context)))
{
    try{
        boost::asio::connect(this->m_s, this->m_resolver.resolve(this->m_host.c_str(), this->m_port.c_str()));
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
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
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return std::string(reply);
}
