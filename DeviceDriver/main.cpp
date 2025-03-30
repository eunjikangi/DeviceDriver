#include "gmock/gmock.h"
#include "DeviceDriver.h"
#include "FlashMemoryDevice.h"

class FlashMock : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};

TEST(TS, read_5»∏»£√‚) {
	FlashMock mock;
	EXPECT_CALL(mock, read(0xA))
		.Times(5);

	DeviceDriver dd{ &mock };
	dd.read(0xA);
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}