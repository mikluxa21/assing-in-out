#include "parallel_executor/ParallelClientExecutor.h"

void ParallelClientExecutor::ParallWorker(int countClients, int countRounds)
{
    std::vector<std::unique_ptr<std::thread>> listOfClients;
    for(size_t i = 0; i < countClients; i++)
    {
        listOfClients.push_back(std::make_unique<std::thread>(std::thread(&InterfaceDeviceClient::run, this, countRounds)));
    }
    for (size_t i = 0; i < countClients; i++)
        if (listOfClients[i]->joinable())
            listOfClients[i]->join();
}
