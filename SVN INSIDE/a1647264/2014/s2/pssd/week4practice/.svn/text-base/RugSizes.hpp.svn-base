#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class RugSizes 
{
  public:
	
	int rugCount(int area)
	{
		int cnt = 0;
		int y;
		for(int i = 2; i < area; i++)
		{
			if(area%i == 0) // we found a factor
			{
				if((i%2 != 0) or ((area/i)%2 != 0) or (area/i==i)) // conditions given by prob. statement
				{
					y = area/i;
					if(y <= i)
					{
						cnt++;
					}
				}
			}
		
		}	
		return cnt+1;
		
		
	}
        
 
};
 
/*int main()
{
      	RugSizes a;
	a.rugCount(100000);
	
}*/
