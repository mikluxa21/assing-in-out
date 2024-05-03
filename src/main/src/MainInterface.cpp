//
// Created by user on 03.05.24.
//

#include "main/MainInterface.h"

MainInterface::MainInterface(int argc, const char **argv)
{
    m_desc.add_options()
            ("help", "produce help message")  // Вызов help справки
            ("rounds,r", po::value<int>(&m_countRounds)->default_value(1), "count rounds for client")
            ("clients,c", po::value<int>(&m_countClients)->default_value(1), "count clients")
            ;
    po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
    po::notify(m_vm);

};

int MainInterface::exec()
{
    if (m_vm.count("help"))
    {
        std::cout << m_desc << std::endl;
        return 1;
    }

    if (this->m_countRounds && this->m_countClients)
    {

    }
    else
    {
        std::cout << "Please, use --help option for information" << std::endl;
        return 1;
    }

    return 0;
}
