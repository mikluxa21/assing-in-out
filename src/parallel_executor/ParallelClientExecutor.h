#ifndef ASYNC_PARALLELCLIENTEXECUTOR_H
#define ASYNC_PARALLELCLIENTEXECUTOR_H

#include "devices/InterfaceDeviceClient.h"

#include <thread>

class ParallelClientExecutor: public InterfaceDeviceClient{
public:
    void ParallWorker(int, int);
};

#endif //ASYNC_PARALLELCLIENTEXECUTOR_H
