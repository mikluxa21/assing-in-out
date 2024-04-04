//
// Created by user on 04.04.24.
//
#include "parallel_executor/DeviceClient.h"

DeviceClient::DeviceClient(size_t name)
    : m_name{std::to_string(name)}, m_client(std::make_unique<Client*>(new Client(m_host, m_port)))
{

}
