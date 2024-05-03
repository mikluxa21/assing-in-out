//
// Created by user on 03.05.24.
//

#ifndef ASYNC_MAININTERFACE_H
#define ASYNC_MAININTERFACE_H

#include "async_server/async_tcp_echo_server.h"
#include "parallel_executor/ParallelClientExecutor.h"

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class MainInterface {
public:
    explicit MainInterface(int argc, const char** argv);
    int exec();

private:
    po::options_description m_desc {"Allowed options"};
    po::variables_map m_vm;
    int m_countRounds;
    int m_countClients;
};


#endif //ASYNC_MAININTERFACE_H
