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
		if (stockCode != "Samsung")
			throw std::exception("Invalid Code");
		if (price == 0)
			throw std::exception("Price is more than 0");
		if (count > 1000000)
			throw std::exception("Count is less than 1000000");

		m_API->buy(stockCode, price, count);
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