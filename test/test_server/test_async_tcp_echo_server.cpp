#include "async_server/async_tcp_echo_server.h"

#include <gtest/gtest.h>

TEST(worker, exceptionDoesNotConnectToServer)
{
    int port = 8080;
    worker workerRun;
    workerRun.run(0);
}