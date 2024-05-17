#include "async_server/ServerMessages.h"

unsigned int ServerMessages::m_counterClients = 1;

ServerMessages::ServerMessages() {}

std::string ServerMessages::GetServerQueshion(std::string& message) {
    std::string result;
    auto mapValues = this->m_interfaceProtobufMessage.ParseMessage(message);

    if(mapValues.empty())
        throw std::runtime_error("ServerMessages::GetServerQueshion: Error into the geted data");

    if(mapValues["message_data"] == "GetId" && mapValues["client_id"] == "")
    {
        result = this->m_interfaceProtobufMessage.CreateMessage(m_counterClients);
        std::cout << "connection established: " << m_counterClients << std::endl;
        m_counterClients++;
    }
    else if(mapValues["message_data"] == "Stop" && mapValues["client_id"] != "")
    {
        result = this->m_interfaceProtobufMessage.CreateMessage();
        std::cout << "connection lost: " << mapValues["client_id"] << std::endl;
    }
    else
    {
        result = message;
    }
    return result;
}


