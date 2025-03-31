#pragma once

#include "StokerBrokerInterface.cpp"
#include "NemoAPI.cpp"

class NemoDriver : public StockerBrockerInterface {
private:
	NemoAPI nemoAPI;
public:
	void selectStockBrocker(bool IsNemo) override {

	}
	void login(string ID, string Password) override {
		nemoAPI.certification(ID, Password);
	}
	void buy(string stockCode, int price, int count) override {

	}
	void sell(string stockCode, int price, int count) override {

	}
	int getPrice(string stockCode, int minute) override {
		return 0;
	}
};