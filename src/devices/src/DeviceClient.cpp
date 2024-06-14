#include "devices/DeviceClient.h"

DeviceClient::DeviceClient()
{
    this->m_client =new Client(this->m_host, this->m_port);
}

void DeviceClient::run(size_t countMessages) {
    for(size_t i  = 0; i < countMessages; i++)
    {
        auto retValue = this->m_client->sendMessage(m_defaultMessage);
    }
}

