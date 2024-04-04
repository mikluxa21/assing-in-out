#include "parallel_executor/DeviceA.h"

std::string DeviceA::getName()
{
  return "A";
}

std::string DeviceA::getDataAsString()
{
  return "A>> Read data";
}

