//
// Created by user on 04.04.24.
//

#ifndef ASYNC_DEVICE_H
#define ASYNC_DEVICE_H

class Device
{
public:
    virtual ~Device() = 0;
    virtual void inWork() = 0;
};
#endif //ASYNC_DEVICE_H
