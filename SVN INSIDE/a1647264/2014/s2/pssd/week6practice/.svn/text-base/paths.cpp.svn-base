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


class ColorfulRabbits
{
  public:
	vector<string> nopass;
	vector<int> min;
	

	int getMinimum(vector<string> inp)
	{
			nopass = inp;
			min.push_back(9999999);
			min.push_back(9999999);				
	}

	void findpath(int x, int y, vector<int> length) 
	{
		if(x < 0 || y < 0 || x>=nopass[0].size() || y>=nopass.size())
		{
			return; // we cant take these paths
		}
		
		if(x>0

		if(nopass[x][y] == 'F') // if we hit the end
		{
			if(length[0] < min[0] && length[1] < min[1])
			{
				min[0] = length[0];
				min[1] = length[1];
			}
			return;
		}

	
		if (nopass[x][y] != 'S')
		{
			return;
		}

   		nopass[x][y] = 'B'; // Leave a mark to show I've been here
		findpath(x,y-1,length+1);  // up
 	 	findpath(x-1,y,length+1);  // left
 		findpath(x,y+1,length+1);  // down
  		findpath(x+1,y,length+1);  // right
		nopass[x][y] = 'S'; // Leave a mark to show I've been here
	}
	
	
	
	
		
		       
};
 
int main()
{
      	ColorfulRabbits a;
	int complearr[] =  	{6, 2, 0, 2, 2, 2, 6, 0, 2, 2, 2, 2, 6, 2, 2, 6, 2, 3, 3, 3, 0, 0, 6, 6, 0};
	vector<int> arr(complearr,complearr + sizeof(complearr) / sizeof(int) );
	int v = a.getMinimum(arr);
	cout << v;

}
