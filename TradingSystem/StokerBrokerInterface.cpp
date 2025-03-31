#pragma once

#include <string>

using std::string;

class StockerBrockerInterface {
public:	
	virtual void selectStockBrocker(bool IsNemo) = 0;
	virtual void login(string ID, string Password) = 0;
	virtual void buy(string stockCode, int price, int count) = 0;
	virtual void sell(string stockCode, int price, int count) = 0;
	virtual int getPrice(string stockCode, int minute) = 0;
};