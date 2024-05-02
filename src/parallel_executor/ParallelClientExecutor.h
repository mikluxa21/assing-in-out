//
// Created by user on 02.05.24.
//

#ifndef ASYNC_PARALLELCLIENTEXECUTOR_H
#define ASYNC_PARALLELCLIENTEXECUTOR_H

#include "devices/DeviceClient.h"

#include <memory>
#include <list>

class ParallelClientExecutor {
public:
    ParallelClientExecutor(size_t countClients = 1, size_t countRounds = 1);
private:
    void run(size_t countClients = 1, size_t countRounds = 1);
};


#endif //ASYNC_PARALLELCLIENTEXECUTOR_H
