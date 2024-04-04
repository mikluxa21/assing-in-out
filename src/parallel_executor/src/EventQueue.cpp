#include "parallel_executor/EventQueue.h"


void EventQueue::push(const std::shared_ptr<const Event> & event)
{
  std::lock_guard<std::mutex> lck(this->mutex);
  this->queue.push(event);
  this->cv.notify_one();
}

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds & duration)
{
  std::unique_lock<std::mutex> lck(this->mutex);
  uint8_t i = 0;
  uint8_t maxWaiting = 5;
  while(this->cv.wait_for(lck, duration, [&i, maxWaiting]{return ++i > maxWaiting;}) == false);
  
  if(this->queue.empty())
  {
    return nullptr;
  }
  else{
    std::shared_ptr<const Event> resEvent = this->queue.front();
    this->queue.pop();
    return resEvent;
  }
    
}

