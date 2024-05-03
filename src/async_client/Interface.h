#ifndef ASYNC_INTERFACE_H
#define ASYNC_INTERFACE_H

#include "parallel_executor/ParallelClientExecutor.h"

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class Interface {
    public:
    explicit Interface(int argc, const char** argv);
    int exec();

    private:
    po::options_description m_desc {"Allowed options"};
    po::variables_map m_vm;
    int m_countRounds;
    int m_countClients;
};

#endif //ASYNC_INTERFACE_H
