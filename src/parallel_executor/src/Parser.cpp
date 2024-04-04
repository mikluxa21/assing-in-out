#include "parallel_executor/Parser.h"

Parser::Parser(std::shared_ptr<EventQueue> queue, std::shared_ptr<Device> A, std::shared_ptr<Device> B) : queue(queue), A(A), B(B)
{
  if(queue == nullptr || A == nullptr || B == nullptr)
    throw std::runtime_error("empty data");
}

void Parser::run(size_t loop_count_A, size_t loop_count_B, int crush_index_A, int crush_index_B)
{
  auto thrA = std::thread(&Parser::read, this, this->A, std::chrono::seconds(1), loop_count_A, crush_index_A);
  auto thrB = std::thread(&Parser::read, this, this->B, std::chrono::seconds(5), loop_count_B, crush_index_B);
  while(true)
  {
    auto resQueuePop = this->queue->pop(std::chrono::seconds(1));
    if(resQueuePop == nullptr)
      break;
    std::cout << resQueuePop->toString() << std::endl;
  }
  thrA.join();
  thrB.join();
}

void Parser::read(std::shared_ptr<Device> device, std::chrono::seconds sleep_duration, size_t loop_count, int crush_index)
{
  this->queue->push(std::make_shared<StartedEvent>(StartedEvent(device)));
  for(size_t i = 0; i < loop_count; i++)
    {
      if(i == crush_index)
        return;
      std::this_thread::sleep_for(sleep_duration);
      this->queue->push(std::make_shared<DataEvent>(DataEvent(device)));
    }
    this->queue->push(std::make_shared<WorkDoneEvent>(WorkDoneEvent(device)));
}
