#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class TomekPhone
{
  public:


	int minKeystrokes(vector<int> freq, vector<int> keySizes)
	{
		int itr = 0;
		int loc[] = {-1,99};
		
		int totkey = 0;
		for(int xx = 0; xx < keySizes.size();xx++)
		{
			totkey+=keySizes[xx];
		}

		if(totkey < freq.size())
			return -1;
		sort(keySizes.begin(),keySizes.end());
		sort(freq.begin(),freq.end(),greater<int>());

		vector<vector<int> > allKeys;		

		for(int i = 0; i < keySizes.size(); i++)
		{	
			vector<int> t;
			allKeys.push_back(t); // Fill with vectors correct size all 0
		}

		for(int j = 0; j < freq.size(); j++)
		{
			//put it in the vector that has the least elements and has space
			bool hasSpace;
			if(itr>=allKeys.size())
			{
				itr = 0;
			}
			if(allKeys[itr].size() < 1)
			{
				allKeys[itr].push_back(freq[j]);
				itr++;
			}
			else
			{
				// Find earliest spot we can put anything in
				while(itr < allKeys.size())
				{
					if(allKeys[itr].size() < keySizes[itr]) // If there actually is a space in the keyVector, we need to find out which space that is 
					{
						int openloc = keySizes[itr] - (keySizes[itr] - allKeys[itr].size());
						if((itr > loc[0]) and (openloc < loc[1]))
						{
							loc[0] = itr;
							loc[1] = openloc;


						}
				
					}
					itr++;
				}
				allKeys[loc[0]].push_back(freq[j]);
				loc[0] = -1;
				loc[1] = 99;
			}
			
		}
		

		int sum = 0;
		for(int x = 0; x < allKeys.size(); x++)
		{	
			for(int y = 0; y < allKeys[x].size(); y++)
			{
				//cout << allKeys[x][y] << " " << " Multiplied by " << y+1 << " " << " is " << allKeys[x][y]*(y+1) << endl;
				sum+= allKeys[x][y]*(y+1);
			}
			//cout << endl;
		}	
		return sum;
	}

	
	
	
		
		       
};
 
/*int main()
{
      	TomekPhone a;
	int complearr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	vector<int> frekz(complearr,complearr + sizeof(complearr) / sizeof(int) );
	
	int keyz[] = {10,10,10,10,10,10,10,10};
	vector<int> keysz(keyz,keyz+sizeof(keyz) / sizeof(int));

	int ans = a.minKeystrokes(frekz,keysz);
	
	cout << ans;

}*/
