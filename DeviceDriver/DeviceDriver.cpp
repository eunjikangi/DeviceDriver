#include "DeviceDriver.h"
#include <iostream>
#include "stdexcept"

using namespace std;

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
    int ret = (int)(m_hardware->read(address));

    if (ret != 0xFF) {
        throw std::exception("ERROR");
    }

    m_hardware->write(address, (unsigned char)data);
}

void DeviceDriver::readAndPrint(int startAddr, int EndAddr)
{
    for (int addr = startAddr; addr <= EndAddr; addr++)
    {
        int ret = (int)(m_hardware->read(addr));
        cout << ret << endl;
    }
}

void DeviceDriver::WriteAll(int value)
{
    int startAddr = 0x0;
    int EndAddr = 0x4;

    for (int addr = startAddr; addr <= EndAddr; addr++)
    {
        m_hardware->write(addr, (unsigned char)value);
    }
}
