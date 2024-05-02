//
// Created by user on 02.05.24.
//

#include "parallel_executor/ParallelClientExecutor.h"

ParallelClientExecutor::ParallelClientExecutor(size_t countClient, size_t countRounds) {
    this->run(countClient, countRounds);
}

void ParallelClientExecutor::run(size_t countClients, size_t countRounds) {
    std::list<std::unique_ptr<std::thread>> listOfClients;
    //for(size_t i = 0; i < countClients; i++)
        //listOfClients.push_back(std::make_unique<std::thread>(std::thread(DeviceClient())));
}
