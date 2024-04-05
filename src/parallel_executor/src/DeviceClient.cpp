//
// Created by user on 04.04.24.
//
#include "parallel_executor/DeviceClient.h"

DeviceClient::DeviceClient()
{
    this->m_client =new Client(this->m_host, this->m_port);
    this->m_name = this->m_client->sendMessage(m_getId);
}

void DeviceClient::inWork(size_t countMessages) {
    for(size_t i  = 0; i < countMessages; i++)
    {
        auto retValue = this->m_client->sendMessage(m_inWork);
        //if() ->Check return value
    }
}

DeviceClient::~DeviceClient() {
    auto retValue = this->m_client->sendMessage(m_stop);
    //if() ->Check return value
}



