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
	int position(int numerator, int denominator)
	{
		int count = 0;
		for ( int i = denominator; i > 1; i-- )
		{
			for( int j = numerator; j > 0; j--)
			{
				//cout << j << "/" << i << endl;
				if(gcd(j, i, j) == 1)
				{
					//cout << " indivisible " << endl;
					count++;
				}
			}
			numerator = i - 2;
		}
		//cout << count;
		return count;
	

	}
	int gcd(int num1, int num2, int div)
	{
		//cout << "check " << num1 << " and " << num2 << "divided by" << div << endl;
		if((num2 % div == 0) and (num1 % div == 0))
		{
			return div;
		}
		gcd(num1,num2,div-1);

	}
	
	
        
 
};
 
/*int main()
{
      	FracCount a;
	int pos = a.position(805,816);
	//cout << pos;    
	//int l = a.gcd(4,6,4);
	//cout << l;    
}*/
