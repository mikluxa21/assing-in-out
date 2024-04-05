//
// Created by user on 04.04.24.
//
#include "parallel_executor/DeviceClient.h"

DeviceClient::DeviceClient()
    : m_client(Client(m_host, m_port)), m_name(std::move(this->m_client.sendMessage(m_getId)))
{}

void DeviceClient::inWork(size_t countMessages) {
    for(auto i  = 0; i < countMessages; i++)
    {
        std::string retValue = this->m_client.sendMessage(m_inWork);
        //if() ->Check return value
    }
}

DeviceClient::~DeviceClient() {
    std::string retValue = this->m_client.sendMessage(m_stop);
    //if() ->Check return value
}



