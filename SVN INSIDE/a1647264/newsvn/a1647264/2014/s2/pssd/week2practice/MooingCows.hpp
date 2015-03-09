#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
using namespace std;


class MooingCows
{
  public:
  	int dissatisfaction(vector<string> farmland)
  	{
		int min = numeric_limits<int>::max();
		int sum = 0;
		int cowpos1;
		for( int i = 0; i < farmland.size(); i++)
		{
			for( int j = 0; j < farmland[i].length(); j++)
			{
				if(farmland[i][j] == 'C') // cow is found
				{
					sum = 0; // Cow is found the distance to all other cows begins at 0
					for(int ii = 0; ii < farmland.size(); ii++)
					{
						for(int jj = 0; jj < farmland[ii].length(); jj++)
						{
							if(farmland[ii][jj] == 'C') // another cow is found, calc distance from orig
							{
								sum+= ( ((i-ii)*(i-ii)) + ((j-jj)*(j-jj)) );
							}
						}
					}
					if(sum < min) // if what we calculated is less than the min, we have a new min
					{
						min = sum;
					}
				}
			}
		}
		return min;
	}	

};

