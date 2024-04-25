//
// Created by user on 25.04.24.
//

#include "async_server/ServerMessages.h"

ServerMessages::ServerMessages() {
    this->m_counterClients = 1;
}

std::string ServerMessages::GetServerQueshion(const std::string& message) {
    std::string result;
    auto mapValues = this->m_interfaceProtobufMessage.ParseMessage(message);
    if(mapValues.empty())
        throw std::runtime_error("Error into the geted data");
    if(mapValues["message_data"] == "GetId" && mapValues["client_id"] == "")
    {
        result = this->m_interfaceProtobufMessage.CreateMessage(this->m_counterClients);
        std::cout << "connection established: " << this->m_counterClients << std::endl;
        this->m_counterClients++;
    }
    else if(mapValues["message_data"] == "Stop" && mapValues["client_id"] != "")
    {
        result = this->m_interfaceProtobufMessage.CreateMessage();
        std::cout << "connection lost: " << mapValues["client_id"] << std::endl;
    }
    else if(mapValues["message_data"] != ""  && mapValues["client_id"] != "")
    {
        result = message;
    }
    else
    {
        result = this->m_interfaceProtobufMessage.CreateMessage("Error");
    }
    return result;
}


