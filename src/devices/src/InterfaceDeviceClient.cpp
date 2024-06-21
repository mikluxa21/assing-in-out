#include "devices/InterfaceDeviceClient.h"

void InterfaceDeviceClient::run(size_t countRounds)
{
    try{
        DeviceClient deviceClient;
        deviceClient.run(countRounds);
    }
    catch(std::exception& e){
        throw std::runtime_error("Exception: " + std::string(e.what()));
    }
   
}
