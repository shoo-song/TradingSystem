#pragma once

#include "StokerBrokerInterface.cpp"
#include "KiwerAPI.cpp"

class KiwerDriver: public StockerBrockerInterface {
private:
	KiwerAPI kiwerAPI;
public:
	void selectStockBrocker(bool IsNemo) override {

	}
	void login(string ID, string Password) override {
		kiwerAPI.login(ID, Password);
	}
	void buy(string stockCode, int price, int count) override {
		kiwerAPI.buy(stockCode, price, count);
	}
	void sell(string stockCode, int price, int count) override {

	}
	int getPrice(string stockCode, int minute) override {
		return 0;
	}
};