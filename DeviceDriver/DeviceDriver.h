#pragma once
#include "FlashMemoryDevice.h"

class DeviceDriver
{
public:
    DeviceDriver(FlashMemoryDevice* hardware);
    int read(long address);
    void write(long address, int data);
    void readAndPrint(int startAddr, int EndAddr);
    void WriteAll(int value);
protected:
    FlashMemoryDevice* m_hardware;

private:
};