#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <queue>
using namespace std;


class TrafficMonitor
{
  public:
	int getMin(vector<string> links)
	{
		bool adjMat[50][50];
		for(int i = 0; i < links.size(); i++)
		{
			for(int j = 0; j < links[0].size(); j++)
			{
				if(links[i][j] == 'Y')
				{
					adjMat[i][j] = 1;
					adjMat[j][i] = 1;
				}
				else
				{
					adjMat[i][j] = 0;
					adjMat[i][j] = 0;
				}
			}
		}

		bool existsLeaf;
    		int delSpot;
    		int ans = 0;
    		do
		{
      			existsLeaf = 0;
      			for(int x = 0; x < links.size(); x++)
			{
  				int linksC = 0;
				for(int y = 0; y < links.size(); y++)
				{
					if (y != x && adjMat[x][y])
					{
						linksC++;
						delSpot = y;
					}
				}

				if (linksC == 1) 
				{
					existsLeaf = 1;
					for(int z = 0; z < links.size(); z++)
					{
						adjMat[delSpot][z] = 0;
						adjMat[z][delSpot] = 0;
				    	}
					ans++;
					
				}
			}

		} while(existsLeaf);

		
		return ans;
	}
	
	
	
	
	
	
		       
};
 
/*int main()
{
      	TrafficMonitor a;
	int l;
	string complearr[] =  {};
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );

	l = a.getMin(comple);
	cout << l;

	
}*/
