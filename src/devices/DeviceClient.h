#ifndef DEVICECLIENT_H
#define DEVICECLIENT_H

#include "client/blocking_tcp_echo_client.h"

#include <string>
#include <memory>

class DeviceClient
{
public:
    DeviceClient();
    void run(size_t);

private:
    std::string m_name;
    Client* m_client;
    std::string m_host = "127.0.0.1";
    std::string m_port = "8080";
    std::string m_defaultMessage = "message";
};

#endif //DEVICECLIENT_H
