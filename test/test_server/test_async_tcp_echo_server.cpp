#include "async_server/async_tcp_echo_server.h"
#include "parallel_executor/ParallelClientExecutor.h"

#include <gtest/gtest.h>

namespace
{
  std::string captureOutput(std::function<void()> func)
  {
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
  }
}

TEST(worker, defaultTest)
{
    int countClients = 5;
    int countRounds = 5;
    int host = 8080;
    worker workerServer;
    ParallelClientExecutor parallelClientExecutor;
    std::string stream = captureOutput([&]() {
        std::thread serverPtr(&worker::run, &workerServer, host);
        serverPtr.detach();
        std::thread clientPtr(&ParallelClientExecutor::ParallWorker, &parallelClientExecutor, std::ref(countClients), std::ref(countRounds));
        if(clientPtr.joinable())
            clientPtr.join();
    });

    for(int i = 1; i < countClients + 1; i++)
        EXPECT_TRUE(stream.find("connection established: " + std::to_string(i)) != std::string::npos);
}