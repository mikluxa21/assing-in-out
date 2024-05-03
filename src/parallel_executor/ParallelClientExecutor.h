//
// Created by user on 02.05.24.
//

#ifndef ASYNC_PARALLELCLIENTEXECUTOR_H
#define ASYNC_PARALLELCLIENTEXECUTOR_H

#include "devices/InterfaceDeviceClient.h"

#include <thread>
#include <memory>

class ParallelClientExecutor: public InterfaceDeviceClient{
public:
    void ParallWorker(size_t, size_t);
};


#endif //ASYNC_PARALLELCLIENTEXECUTOR_H
