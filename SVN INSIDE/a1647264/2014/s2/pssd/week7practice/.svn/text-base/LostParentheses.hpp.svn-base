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

class LostParentheses
{
  public:


	int minResult(string s)
	{
		int left;
		bool leftdone = 0;
		int prevpos = 0;
		int i = 0;
		int count = 0;
		bool neg = 0;
		
		while(i < s.size())
		{
			
			if(s[i] == '-') // find our first minus
			{
				neg = 1;
				prevpos = i + 1; // the position of the last '-' we found
				if(!leftdone) // we havent put in the left part
				{
					left = getSum(s.substr(0,i));
					//cout << "the left of the first minus is " << left << endl;
					leftdone = 1;
				}
				
				// Time to find the next minus
				bool done = 0;
				for(int x = prevpos; x < s.size(); x++)
				{	
					if(s[x] == '-')
					{	
						
						//cout << "Between the minus at " << prevpos << " and " << x << " is " << s.substr(prevpos,(x-prevpos)) << endl;
						left-= getSum(s.substr(prevpos,(x-prevpos)));
						prevpos = x+1;
						done = 1;
						break;
					}

				}

				if(!done)
				{
					left-= getSum(s.substr(prevpos));
				}

			}

	
			i++;
		}


		if(!neg)
		{
			return getSum(s);
		}

		return left;
	}

	int getSum(string s)
	{
		int prevpos = 0;
		char lastchar = '+';
		int sum = 0;
		string part;
		bool after = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '+') // if a plus is found, find the next plus or minus then add or find the end
			{
				part = s.substr(prevpos,(i-prevpos)); // we want the substring before the +
				prevpos = i+1;
				lastchar = '+';
				sum+=atoi(part.c_str());
				after == 1;
				
				
			}

			if(s[i] == '-') // if a plus is found, find the next plus or minus then add or find the end
			{
				part = s.substr(prevpos,(i-prevpos)); // we want the substring before the +
				prevpos = i+1;
				lastchar = '-';
				if(after == 1)
					sum+=atoi(part.c_str());
				else
				{
					sum-=atoi(part.c_str());
					after == 1;
				}
				
			}
			
		}

		if(lastchar=='+')
		{
			part = s.substr(prevpos);
			sum+= atoi(part.c_str());
		}
		else
		{
			part = s.substr(prevpos);
			sum-= atoi(part.c_str());
		}
		return sum;
	}

	
	
	
		
		       
};
 
/*int main()
{
		
      	LostParentheses a;
	int v = a.minResult("10+20+30");
	cout << v;
	//cout << a.getSum(1);
}*/
