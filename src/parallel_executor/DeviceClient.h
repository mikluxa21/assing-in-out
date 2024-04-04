//
// Created by user on 04.04.24.
//

#ifndef ASYNC_DEVICECLIENT_H
#define ASYNC_DEVICECLIENT_H

#include <string>
#include <memory>

#include "Device.h"
#include "async_client/blocking_tcp_echo_client.h"


class DeviceClient: public Device
{
public:
    DeviceClient(size_t);
    void inWork() override;
    ~DeviceClient() override;

private:
    std::string m_name;
    std::unique_ptr<Client*> m_client;
    std::string m_host = "127.0.0.1";
    std::string m_port = "8080";

};
#endif //ASYNC_DEVICECLIENT_H
