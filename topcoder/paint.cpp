#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <bitset>
using namespace std;


class PastingPaintingDivTwo
{
  public:
	

	int countColors(vector<string> a, long long n)
	{
			int cnt = 0;
			int repcnt = 0;
			for(int i = 0; i < a.size(); i++)
			{
				for(int j = 0; j < a[0].size(); j++)
				{
					if(a[i][j]=='B')
					{
						if( i+1 < a.size() && j+1 < a[0].size() )
						{
							if( a[i+1][j+1]!='B' )
								cnt++;
							else
								repcnt++;
						}
						else
						{
							cnt++;
						}
					}
				}
			}
			long long ans = cnt*n + repcnt;
			cout << ans;
	}
	

	
	
	
		       
};
 
int main()
{
      	PastingPaintingDivTwo a;

	string arr[] = {
"..........B..........",
".........B.B.........",
"........B...B........",
".......B.....B.......",
"......B..B.B..B......",
".....B...B.B...B.....",
"....B...........B....",
"...B...B.....B...B...",
"..B.....BBBBBB....B..",
".B..........BB.....B.",
"BBBBBBBBBBBBBBBBBBBBB"
};
	vector<string> mon(arr,arr + sizeof(arr) / sizeof(string) );

	int v = a.countColors(mon,1000000000);


	
}
