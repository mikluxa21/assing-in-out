#include "client/Interface.h"

Interface::Interface(int argc, const char **argv)
{
    m_desc.add_options()
            ("help,h", "produce help message")
            ("clients,c", po::value<int>(&this->m_countClients)->default_value(1), "count clients")
            ("rounds,r", po::value<int>(&this->m_countRounds)->default_value(1), "count rounds for client")
            ;
    po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
    po::notify(m_vm);
}

int Interface::exec()
{
    if (m_vm.count("help")){
        std::cout << m_desc << std::endl;
        return 1;
    }
    if (this->m_countRounds > 0 && this->m_countClients > 0){
        ParallelClientExecutor parallelClientExecutor;
        parallelClientExecutor.ParallWorker(this->m_countClients, this->m_countRounds);
    }
    else{
        std::cout << "Please, use --help option for information" << std::endl;
        return 1;
    }
    return 0;
}
