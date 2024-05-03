#include "devices/InterfaceDeviceClient.h"

void InterfaceDeviceClient::run(size_t countRounds)
{
    DeviceClient deviceClient;
    deviceClient.inWork(countRounds);
}
