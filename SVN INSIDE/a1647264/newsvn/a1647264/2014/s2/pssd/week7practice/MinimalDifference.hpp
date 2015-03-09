#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <climits>
using namespace std;
/*

							            ▄▐
							      ▄▄▄  ▄██▄
							     ▐▀█▀▌    ▀█▄
							     ▐█▄█▌      ▀█▄
							      ▀▄▀  ▄▄▄▄▄▀▀
							   ▄▄▄██▀▀▀▀
							   █▀▄▄▄█ ▀▀
							   ▌ ▄▄▄▐▌▀▀▀
							▄ ▐   ▄▄ █ ▀▀ U HAVE BEEN SPOOKED BY THE
							▀█▌   ▄ ▀█▀ ▀
							       ▄▄▐▌▄▄
							       ▀███▀█ ▄
							      ▐▌▀▄▀▄▀▐▄SPOOKY SKILETON
							      ▐▀       ▌
							      █        █
							     ▐▌         █
							     █          ▐▌



*/

class MinimalDifference
{
  public:


	int findNumber(int a, int b, int c)
	{
		int ret;
		int csum = getSum(c);
		int diff = numeric_limits<int>::max();
		for(int i = a; i <= b; i++)
		{
			int num = getSum(i);
			if(abs(num-csum) < diff)
			{
				ret = i;
				diff = abs(num-csum);
			}
		}

		return ret;
	}

	int getSum(int a)
	{
		int sum = 0;
		do {
			int digit = a % 10;
			sum+= digit;
			a /= 10;
		} while (a > 0);
		return sum;
	}

	
	
	
		
		       
};
 
/*int main()
{
		
      	MinimalDifference a;
	int v = a.findNumber(100,1000,99);
	cout << v;
	//cout << a.getSum(1);
}*/
