//
// Created by user on 25.04.24.
//

#ifndef ASYNC_SERVERMESSAGES_H
#define ASYNC_SERVERMESSAGES_H

#include "protobuf/parser/InterfaceProtobufMessage.h"

#include <stdexcept>

class ServerMessages {
public:
    ServerMessages();
    std::string GetServerQueshion(const std::string&);

private:
    InterfaceProtobufMessage m_interfaceProtobufMessage;
    size_t m_counterClients;

};


#endif //ASYNC_SERVERMESSAGES_H
