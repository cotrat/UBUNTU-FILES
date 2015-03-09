#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class CastleGuards
{
  public:
	


	int missing(vector<string> castle)
	{
		
		int rows = castle.size();
		int columns = castle[0].size();
		int addedr = 0;
		int addedc = 0;
		bool noguard;
		for(int i = 0; i < rows; i++)
		{
			noguard = true;
			for(int j = 0; j < columns; j++)
			{
				if(castle[i][j] == 'X')
				{
					noguard = false; 
				}
			}
			if(noguard) addedr++;
		}

		

		for(int u = 0; u < columns; u++)			
		{
			noguard = true;
			for(int v = 0; v < rows; v++)	
			{
				if(castle[v][u] == 'X')
				{
					noguard = false;
				}
			}
			if(noguard) addedc++;
		}
		cout << addedr << "  " << addedc;
		return max(addedr,addedc);
	}
	
	
	
	
	
	
		       
};
 
/*int main()
{
      	CastleGuards a;
	int l;
	string complearr[] =      	
{".X.............", "......X.....X..", "...............", "..X.......X....", "X....X.....X...", "X.......X......", "...X...........", "..X............", "...........X...", "...............", "....X.X....XX..", ".........X.....", ".....X........."};	
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );
	l = a.missing(comple);
	cout << l;

	
}*/
