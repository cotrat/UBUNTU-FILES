#include "EfficientFibonacci.h"
#include <string>
#include <iostream>

using namespace std;


EfficientFibonacci::EfficientFibonacci() : m_calculated(500)
{
 // Initialising m_calulated to have a size of 500, this is an arbitrary size (i.e. this program could calculated up to 500 fibonacci numbers) if there 
 // No other issues with counting up to 500 fibonacci numbers
}

EfficientFibonacci::~EfficientFibonacci()
{

}

bool EfficientFibonacci::checkWord(string to_check)
{
	
	for(unsigned int i = 0;i < to_check.length();i++)
	{
		if(!isdigit(to_check[i]))
		{
			return 0;
		}
	}
	return 1;
}

int EfficientFibonacci::ApplySlowFibonacci(int num)
{
	/*
	static int count=0;
    	count++;			This is simply just for checking how many calls it took (to see how slow this algorithm is)
	cout << count << endl;
	*/
	if (num == 0)
	{
		return 0;
	}
	if (num == 1 or num == 2)
	{
		return 1;
	}

    	return ApplySlowFibonacci(num - 1)+ApplySlowFibonacci(num - 2);
}


int EfficientFibonacci::ApplyEfficientFibonacci(int num)
{
	/*
	static int count=0;
    	count++;			This is simply just for checking how many calls it took (to see how much faster this algorithm is)
	cout << count << endl;
	*/

	if (num==0)
	{
		return 0;
	}
	if (num==1 or num==2)
	{
		return 1;
	}
	// Simple base cases, if we have a num that is 1 or 2 we return 1, if the num is 0 we return 0

	if(m_calculated[num] != 0) // If the value in our vector is not zero (i.e. it actually has been set to something we can just return the valuea t that index_
		return m_calculated[num];
	else
	{
		// If the value isnt set, we simply calculate and set this value recursively then return it
		m_calculated[num] = ApplyEfficientFibonacci(num - 1) + ApplyEfficientFibonacci(num - 2);
		return m_calculated[num];
	}
	


}
