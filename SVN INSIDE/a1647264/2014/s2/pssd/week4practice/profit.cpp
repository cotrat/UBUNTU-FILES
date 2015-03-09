#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class TimeTravellingCellar // started 7
{
  public:
	
	void determineProfit(vector<int> profit, vector<int> decay)
	{
		int max = 0;
		int maxdex;
		int min = 10001;
		int mindex;
		int max2 = 0;
		int min2 = 10001;
		for(int i = 0; i < profit.size(); i++)
		{
			if(profit[i]>max)
			{
				max = profit[i];
				maxdex = i;
			}
			if(decay[i]<min)
			{	
				mindex = i;
				min = decay[i];
			}
		}
		//cout << "MAX INDEX " << maxdex << " MIN INDEX " << mindex << endl;
		if(maxdex == mindex) // we cant use the same one twice
		{
			
			for(int j = 0; j < profit.size(); j++)
			{
				if(profit[j]>max2 && j!=maxdex)
				{
					max2 = profit[j];
				}
				if(decay[j]<min2 && j!=mindex)
				{
					min2 = decay[j];
				}
			}
		}
		else
		{
			//cout << max-min << "did the else" << endl;
			return max-min;
		}

		//cout << " SECOND HIGHEST IS " << max2 << endl;

		return std::max(max-min2,max2-min);

		
		
	}
        
 
};
 
/*int main()
{
      	TimeTravellingCellar a;
	int complearr[] = {8209, 651};
	vector<int> profit(complearr,complearr + sizeof(complearr) / sizeof(int) );

	//Output expected: 2250
	//Output recieved: -4061
	int dec[] = {4712, 5959};
	vector<int> decay(dec,dec + sizeof(dec) / sizeof(int) );
	a.determineProfit(profit,decay);
}*/
