//
// Created by user on 02.05.24.
//

#include "devices/InterfaceDeviceClient.h"

void InterfaceDeviceClient::run(size_t countRounds) {
    DeviceClient deviceClient;
    deviceClient.inWork(countRounds);
}
