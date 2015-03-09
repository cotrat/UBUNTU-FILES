#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock {

	public:
		Stock(std::string name, int price, int amount);
		int getPrice() const;
		bool checkOrder(int amt) const;
		void decStock(int amt);
		void incStock(int amt);
		~Stock();
	private:
		int m_price;
		std::string m_name;
		int m_amount;

};
#endif
