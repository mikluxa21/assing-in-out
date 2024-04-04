#include "parallel_executor/StartedEvent.h"

std::string StartedEvent::toString() const
{
  return "Started " + this->device.get()->getName();
}


