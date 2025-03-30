#include "gmock/gmock.h"
#include "DeviceDriver.h"
#include "FlashMemoryDevice.h"

using namespace testing;

class FlashMock : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};

TEST(TS, 5회_Read) {
	FlashMock mock;
	EXPECT_CALL(mock, read(0xA))
		.Times(5);

	DeviceDriver dd{ &mock };
	dd.read(0xA);
}

TEST(TS, 5회_Read시_모두같은값) {
	FlashMock mock;
	EXPECT_CALL(mock, read(0xA))
		.WillOnce(Return(0xB))
		.WillOnce(Return(0xB))
		.WillOnce(Return(0xB))
		.WillOnce(Return(0xB))
		.WillOnce(Return(0xC));

	DeviceDriver dd{ &mock };

	EXPECT_THROW(dd.read(0xA), std::exception);
}

TEST(TS, isWritten) {
	FlashMock mock;
	EXPECT_CALL(mock, read(0xA))
		.WillOnce(Return(0xD));

	DeviceDriver dd{ &mock };
	EXPECT_THROW(dd.write(0xA, 0xC), std::exception);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}