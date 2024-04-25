#include "devices/DeviceClient.h"

DeviceClient::DeviceClient()
{
    this->m_client =new Client(this->m_host, this->m_port);
    auto retValue = this->m_client->sendMessage(m_interfaceProtobufMessage.CreateMessage(m_getId));
    auto parseId = this->m_interfaceProtobufMessage.ParseMessage(retValue);
    //if() ->Check return value
    this->m_name = parseId["client_id"];
}

void DeviceClient::inWork(size_t countMessages) {
    for(size_t i  = 0; i < countMessages; i++)
    {
        auto retValue = this->m_client->sendMessage(this->m_interfaceProtobufMessage.CreateMessage(m_inWork));
        auto parseMessage = this->m_interfaceProtobufMessage.ParseMessage(retValue);
        //if() ->Check return value with client ID
        //parseMessage["message_data"]
    }
}

DeviceClient::~DeviceClient() {
    auto retValue = this->m_client->sendMessage(this->m_interfaceProtobufMessage.CreateMessage(m_stop));
    auto parseMessage = this->m_interfaceProtobufMessage.ParseMessage(retValue);
    //if() ->Check return value with client ID
    //parseMessage["message_data"]
}



