#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class MonsterValley2 // started 8 50
{
  public:
	
	int min_cost(vector<int> monsters, vector<int> costs)
	{
		int length = monsters.size();
		
		vector<int> indexes;
		int min = 500;
		for (int s = 1; s < (1 << length); ++s)    // iterate through all non-null sets
   		{
			vector<int> check(length,0);
        		for (int e = 0; e < length; ++e)       // for each set element
        		{
            			if (s & (1 << e))                     // test for membership of set
            			{
                			check[e] = 1;
            			}
       			 }
			int ll = checkp(check, monsters, costs);
        		if( ll < min)
			{
				min = ll;
			}
    		}
		cout << min;	
	}

	int checkp(vector<int> buy_loc, vector<int> monsters, vector<int> costs)
	{
		long long dread = 0;
		int cost = 0;
		if(buy_loc[0] == 0) // If the first one isnt a buy, we cant go any further
		{
			return 50;
		}
		
		for(int i = 0; i < buy_loc.size(); i++)
		{
			if(buy_loc[i] == 1)
			{
				dread += monsters[i];
				cost += costs[i];
			}
			else if(dread < monsters[i])
			{
				return 50;
			}
			



			/*if(dread < monsters[i] && buy_loc[i] == 0) // We arent buying, AND we dont have enough dread
			{
				return 50;
			}
		
			if(buy_loc[i] == 1) // Buy this specific monster
			{
				dread = dread + monsters[i];
				cost = cost + costs[i];
			}

			/*if(i+1 < buy_loc.size())
			{
				if(dread < monsters[i+1])
					return 50;
			}
			/*if(dread < monsters[i])
			{
				return 50;
			}*/
			
		}
		return cost;
	
	}

        
 
};
 
int main()
{
      	MonsterValley2 a;

	int arr[] =  {1, 2, 4, 6, 16, 19, 64, 105, 256, 464, 1024, 1463, 4096, 4515, 16384, 21445, 65536, 68543, 262144, 479277};
	vector<int> mon(arr,arr + sizeof(arr) / sizeof(int) );
 
	int arr2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	vector<int> cc(arr2,arr2 + sizeof(arr2) / sizeof(int) );

	int sum = a.min_cost(mon,cc);
	 	
	

}
