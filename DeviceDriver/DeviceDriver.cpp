#include "DeviceDriver.h"
#include "stdexcept"

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{
}

int DeviceDriver::read(long address)
{
    int prevData = -1;

    for (int readCount = 0; readCount < 5; readCount++) {
        int curData = (int)(m_hardware->read(address));

        if (prevData != -1 && curData != prevData) {
            throw std::exception("ERROR");
        }

        prevData = curData;
    }

    return prevData;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}