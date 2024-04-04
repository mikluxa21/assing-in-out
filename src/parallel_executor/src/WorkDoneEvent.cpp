#include "parallel_executor/WorkDoneEvent.h"

std::string WorkDoneEvent::toString() const
{
  return "Finished " + this->device.get()->getName();
}
