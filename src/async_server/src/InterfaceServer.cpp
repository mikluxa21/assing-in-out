#include "async_server/InterfaceServer.h"

InterfaceServer::InterfaceServer(int argc, const char **argv) {
    m_desc.add_options()
            ("help,h", "produce help message")  // Вызов help справки
            ("port,p", po::value<int>(&this->m_port)->default_value(8080), "port name")
            ;
    po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
    po::notify(m_vm);
}

int InterfaceServer::exec() {
    if (m_vm.count("help")){
        std::cout << m_desc << std::endl;
        return 1;
    }else {
        worker work;
        work.run(this->m_port);
        return 0;
    }
}

