#include "DeviceDriver.h"
#include "stdexcept"

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{
}

int DeviceDriver::read(long address)
{
    // TODO: implement this method properly
    int ret = (int)(m_hardware->read(address));

    for (int i = 0; i < 4; i++) {
        int b = (int)(m_hardware->read(address));
        if (ret != b) {
            throw std::exception("ERROR");
        }
    }

    return ret;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}