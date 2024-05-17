#ifndef ASYNC_INTERFACESERVER_H
#define ASYNC_INTERFACESERVER_H

#include "async_server/async_tcp_echo_server.h"

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class InterfaceServer {
public:
    explicit InterfaceServer(int argc, const char** argv);
    int exec();

private:
    po::options_description m_desc {"Allowed options"};
    po::variables_map m_vm;
    int m_port;
};

#endif //ASYNC_INTERFACESERVER_H
