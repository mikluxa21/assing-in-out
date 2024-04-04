#include "parallel_executor/EventQueue.h"
#include "parallel_executor/DeviceA.h"
#include "parallel_executor/DeviceB.h"
#include "parallel_executor/Parser.h"

#include <boost/program_options.hpp>


namespace po = boost::program_options;

class EApplication
{
public:
  explicit EApplication(int argc, const char** argv);
  int exec();

private:
  po::options_description m_desc {"Allowed options"};
  po::variables_map m_vm; 
  
  size_t m_loop_count_A;
  size_t m_loop_count_B;
  int m_crush_index_A;
  int m_crush_index_B;
};

EApplication::EApplication(int argc, const char **argv)
{
    m_desc.add_options()
            ("help", "produce help message")  // Вызов help справки
            ("loop-A,lA", po::value<size_t>(&m_loop_count_A)->composing(), "loop count for A device")  
            ("loop-B,lB", po::value<size_t>(&m_loop_count_B)->composing(), "loop count for B device")            
            ("crush-A,cA", po::value<int>(&m_crush_index_A)->default_value(-1), "crush index for A device")
            ("crush-B,cB", po::value<int>(&m_crush_index_B)->default_value(-1), "crush index for B device")
            ;
    po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
    po::notify(m_vm);
}

int EApplication::exec()
{
  if (m_vm.count("help"))
  {
    std::cout << m_desc << std::endl;
    return 1;
  }

  if (this->m_loop_count_A && this->m_loop_count_B)
  {
    std::shared_ptr<EventQueue> queue = std::make_shared<EventQueue>();
    std::shared_ptr<Device> A = std::make_shared<DeviceA>();
    std::shared_ptr<Device> B = std::make_shared<DeviceB>();
    Parser parser(queue, A, B);
    parser.run(this->m_loop_count_A, this->m_loop_count_B, this->m_crush_index_A, this->m_crush_index_B);
  }
  else
  {
    std::cout << "Please, use --help option for information" << std::endl;
    return 1;
  }
  
  return 0;
}

int main(int argc, const char** argv)
{
    EApplication app(argc, argv);
    return app.exec();
}

