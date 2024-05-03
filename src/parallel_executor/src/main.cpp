//
// Created by user on 02.05.24.
//
#include "parallel_executor/ParallelClientExecutor.h"

int main()
{
    ParallelClientExecutor parallelClientExecutor;
    parallelClientExecutor.ParallWorker(6, 1);
    return 0;
}