#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;
 

class FracCount
{
  public:
	int Position(int numerator, int denominator)
	{
		int pos= 0;
		int total;
		for(int i = denominator; i > 1; i--)
		{
			total =  dop(denominator-(denominator-i), i, 0);
			pos +=total;
		}
		return pos;
	

	}
	int gcd(int num1, int num2, int div)
	{
		/*if(num2 == 0) // weve reached the bottom
		{
			return num1; // 
		}
		else
		{
			gcd(num2, num1 % num2);
		}*/
		if((num2 % div == 0) and (num1 % div == 0))
		{
			return div;
		}
		gcd(num1,num2,div-1);

	}
	int dop(int numerator, int denominator, int count)
	{
		
		if(numerator == 1)
		{
			return count+1; // If we got down to 0, return how many it took to get down
		}
		else if(gcd(numerator,denominator,numerator)==1)
		{
			dop(numerator-1, denominator, count+1); // If its reducible check next but dont add to count
		}
		else // if they arent reducible check next and add to count
		{
			dop(numerator-1, denominator, count);
		}
	}
	
        
 
};
 
/*int main()
{
      FracCount a;
	int pos = a.Position(999,1000);
	cout << pos;        
}*/
