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
    DeviceClient();
    void inWork(size_t) override;
    ~DeviceClient() override;

private:
    std::string m_name;
    Client m_client;
    std::string m_host = "127.0.0.1";
    std::string m_port = "8080";
    std::string m_getId = "GetId";
    std::string m_inWork = "Work";
    std::string m_stop = "Stop";

};
#endif //ASYNC_DEVICECLIENT_H
