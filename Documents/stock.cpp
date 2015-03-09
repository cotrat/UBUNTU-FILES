#include <string>
#include "Stock.h"

Stock::Stock(std::string name, int price, int amount)
{
	m_name = name;	
	m_price = price;
	m_amount = amount;
}

void Stock::decStock(int amt)
{
	m_amount = m_amount - amt;
}

void Stock::incStock(int amt)
{
	m_amount = m_amount + amt;
}

bool Stock::checkOrder(int amt) const
{
	if(amt > m_amount)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Stock::getPrice() const
{
	return m_price;
}
