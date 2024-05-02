//
// Created by user on 04.04.24.
//


#include "devices/InterfaceDeviceClient.h"


int main()
{
    for(size_t i = 0; i < 10; i++) {
        InterfaceDeviceClient interfaceDeviceClient;
        interfaceDeviceClient.run(3);
    }
    return 0;
}