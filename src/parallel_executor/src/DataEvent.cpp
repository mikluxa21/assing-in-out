#include "parallel_executor/DataEvent.h"

std::string DataEvent::toString() const
{
  return " from " + this->device.get()->getName();
}

