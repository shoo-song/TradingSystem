#pragma once

#include "StokerBrokerInterface.cpp"

class StockerBrockerDriver {
public:
	StockerBrockerDriver(StockerBrockerInterface* API) {
		m_API = API;
	}
	void login(string ID, string Password) {
		m_API->login(ID, Password);
	}
	void buy(string stockCode, int price, int count) {

	}
	void sell(string stockCode, int price, int count) {

	}
	int getPrice(string stockCode, int minute) {
		return 0;
	}
	void buyNiceTiming(string stockCode, int price) {

	}
	void sellNiceTiming(string stockCode, int count) {

	}
private:
	StockerBrockerInterface* m_API;
};