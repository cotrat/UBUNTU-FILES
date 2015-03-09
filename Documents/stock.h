#ifndef STOCK_H
#def STOCK_H

#include <string>

class Stock {

	public:
		Stock(string name, int price, int amount);
		int getPrice() const;
		bool checkOrder(int amt) const;
		void decStock(int amt);
		void incStock(int amt);
		~Stock();
	private:
		int m_price;
		string m_name;
		int m_amount;

	
