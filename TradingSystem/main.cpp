#include "gmock/gmock.h"
#include <iostream>
#include "NemoAPI.cpp"
#include "KiwerAPI.cpp"
using namespace std;
class StockerBrockerInterface {
public:
	virtual void selectStockBrocker(bool IsNemo) = 0;
	virtual void login(string ID, string Password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode, int minute) = 0;
};
class MockDriver : public StockerBrockerInterface {
public:
	MOCK_METHOD(void, selectStockBrocker, (bool IsNemo), (override));
	MOCK_METHOD(void, login, (string ID, string Password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int count), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int count), (override));
	MOCK_METHOD(int, getPrice, (string stockCode, int minute), (override));
};
class StockerBrockerDriver {
public:
	StockerBrockerDriver(StockerBrockerInterface* API) {
		m_API = API;
	}
	void login(string ID, string Password) {

	}
	void buy(string stockCode, int price, int count) {

	}
	void sell(string stockCode, int price, int count) {

	}
	int getPrice(string stockCode, int minute) {

	}
private:
	StockerBrockerInterface* m_API;
};

TEST(Trading, LoginTest) {
	// Login
	MockDriver Mock;
	EXPECT_CALL(Mock, login("shoo-song", "1234"))
		.Times(1);
	StockerBrockerDriver Driver{ &Mock };
	Driver.login("shoo-song", "1234");
}
TEST(Trading, BuyTest) {
	// Buy
}
TEST(Trading, SellTest) {
	// Sell
}
TEST(Trading, getPrice) {
	// getPrice
}
int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}