#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class MonstersValley2
{
  public:
	vector<int> monstersg;
	vector<int> costsg;
	int minimumPrice(vector<int> monsters, vector<int> costs)
	{
		int length = monsters.size();
		costsg = costs;
		monstersg = monsters;
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
			int ll = checkp(check);
        		if( ll < min)
			{
				min = ll;
			}
    		}
		return min;	
	}

	int checkp(vector<int> buy_loc)
	{
		long long dread = 0;
		int cost = 0;
		bool poss = 1;
		for(int i = 0; i < buy_loc.size(); i++)
		{
			if(buy_loc[i] == 1)
			{
				dread += monstersg[i];
				cost += costsg[i];
			}
			else if(dread < monstersg[i])
			{
				poss = 0;	
				break;
			}
				
		}
		if(poss)
			return cost;
		return 600;
	
	}

        
 
};
 
/*int main()
{
      	MonsterValley2 a;

	int arr[] =  {1, 2, 4, 6, 16, 19, 64, 105, 256, 464, 1024, 1463, 4096, 4515, 16384, 21445, 65536, 68543, 262144, 479277};
	vector<int> mon(arr,arr + sizeof(arr) / sizeof(int) );
 
	int arr2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	vector<int> cc(arr2,arr2 + sizeof(arr2) / sizeof(int) );

	int sum = a.min_cost(mon,cc);
	 	
	

}*/
