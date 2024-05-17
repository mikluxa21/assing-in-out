#include "devices/DeviceClient.h"

DeviceClient::DeviceClient()
{
    this->m_client =new Client(this->m_host, this->m_port);
    std::string strMessage = m_interfaceProtobufMessage.CreateMessage(m_getId);
    auto retValue = this->m_client->sendMessage(strMessage);
    auto parseId = this->m_interfaceProtobufMessage.ParseMessage(retValue);
    this->m_name = parseId["client_id"];
}

void DeviceClient::inWork(size_t countMessages) {
    for(size_t i  = 0; i < countMessages; i++)
    {
        this->m_interfaceProtobufMessage.SetClientId(stoi(this->m_name));
        auto retValue = this->m_client->sendMessage(this->m_interfaceProtobufMessage.CreateMessage(m_inWork));
        auto parseMessage = this->m_interfaceProtobufMessage.ParseMessage(retValue);
    }
}

DeviceClient::~DeviceClient() {
    auto retValue = this->m_client->sendMessage(this->m_interfaceProtobufMessage.CreateMessage(m_stop));
    auto parseMessage = this->m_interfaceProtobufMessage.ParseMessage(retValue);
}



