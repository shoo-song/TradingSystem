#include "gmock/gmock.h"
#include <iostream>
using namespace std;
class StockerBrocker {
public:
	virtual bool login(string ID, string Password) = 0;
private:
	
};
class Kiwer : public StockerBrocker{
public:
	bool login(string ID, string Password) override{
		//TODO
	}
};
class Nemo : public StockerBrocker {
public:
	bool login(string ID, string Password) override{
		//TODO
	}
};
TEST(Trading, SelectTest) {
	// selct App
}
TEST(Trading, LoginTest) {
	// Login
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