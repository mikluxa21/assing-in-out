#include "async_server/async_tcp_echo_server.h"

#include <gtest/gtest.h>
// https://habr.com/ru/companies/pt/articles/166139/

TEST(worker, exceptionDoesNotConnectToServer)
{
    int port = 8080;
    worker workerRun;
    workerRun.run(0);
}