#include "gmock/gmock.h"
#include <iostream>
#include "StockerBroker.cpp"
#include "NemoDriver.cpp"
#include "KiwerDriver.cpp"
using namespace std;
using namespace testing;

class MockDriver : public StockerBrockerInterface {
public:
	MOCK_METHOD(void, selectStockBrocker, (bool IsNemo), (override));
	MOCK_METHOD(void, login, (string ID, string Password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int count), (override));
	MOCK_METHOD(int, getPrice, (string stockCode, int minute), (override));
};

class TradingFixture : public Test {
public:
	MockDriver Mock;
	StockerBrockerDriver Driver{ &Mock };
};
TEST_F(TradingFixture, LoginTest) {
	// Login
	EXPECT_CALL(Mock, login("shoo-song", "1234"))
		.Times(1);
	Driver.login("shoo-song", "1234");
}
TEST_F(TradingFixture, BuyTest_없는종목) {
	EXPECT_THROW(Driver.buy("Invalid Code", 1000, 10), std::exception);
}
TEST_F(TradingFixture, BuyTest_가격0원) {
	EXPECT_THROW(Driver.buy("ABCD", 0, 10), std::exception);
}
TEST_F(TradingFixture, BuyTest_한도수량초과) {
	EXPECT_THROW(Driver.buy("ABCD", 1000, 10000000000), std::exception);
}
TEST_F(TradingFixture, SellTest_정상동작) {
	Driver.buy("ABCD", 1000, 10);
	EXPECT_NO_THROW(Driver.sell("ABCD", 1000, 10), std::exception);
}
TEST_F(TradingFixture, SellTest_보유하지않은종목) {
	EXPECT_THROW(Driver.sell("ABCD", 1000, 10), std::exception);
}
TEST_F(TradingFixture, SellTest_보유량초과) {
	Driver.buy("ABCD", 1000, 10);
	EXPECT_THROW(Driver.sell("ABCD", 1000, 20), std::exception);
}
TEST_F(TradingFixture, getPrice_정상동작) {
	EXPECT_NO_THROW(Driver.getPrice("ABCD", 10), std::exception);
}
TEST_F(TradingFixture, getPrice_없는종목) {
	EXPECT_THROW(Driver.getPrice("Invalid Code", 10), std::exception);
}
TEST_F(TradingFixture, buyNiceTiming_정상동작) {
	EXPECT_CALL(Mock, buy("ABCD", 1000, 10));
	EXPECT_NO_THROW(Driver.buyNiceTiming("ABCD", 1000), std::exception);
}
TEST_F(TradingFixture, buyNiceTiming_없는종목) {
	EXPECT_CALL(Mock, buy("Invalid Code", 1000, 10));
	EXPECT_THROW(Driver.buyNiceTiming("Invalid Code", 1000), std::exception);
}
TEST_F(TradingFixture, sellNiceTiming_정상동작) {
	EXPECT_CALL(Mock, sell("ABCD", 1000, 10));
	EXPECT_NO_THROW(Driver.sellNiceTiming("ABCD", 10), std::exception);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}