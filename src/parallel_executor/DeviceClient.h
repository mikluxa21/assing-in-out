//
// Created by user on 04.04.24.
//

#ifndef DEVICECLIENT_H
#define DEVICECLIENT_H

#include "async_client/blocking_tcp_echo_client.h"
#include "protobuf/parser/DelimitedMessagesStreamParser.h"
#include "protobuf/parser/Parser.h"
#include "src/protobuf/protobuf/message.pb.h"

#include <string>
#include <memory>


class DeviceClient
{
public:
    DeviceClient();
    void inWork(size_t);
    ~DeviceClient();

private:
    std::string m_name;
    Client* m_client;
    std::string m_host = "127.0.0.1";
    std::string m_port = "8080";
    std::string m_getId = "GetId";
    std::string m_inWork = "Work";
    std::string m_stop = "Stop";

};
#endif //DEVICECLIENT_H
