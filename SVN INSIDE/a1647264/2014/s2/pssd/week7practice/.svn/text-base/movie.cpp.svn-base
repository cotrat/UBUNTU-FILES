#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class VeryInterestingMovie
{
  public:
	

	int maximumPupils(vector<string> seats)
	{
		int max = 0;
		for(int i = 0; i < seats.size(); i++)
		{
			for(int j = 0; j < seats[i].size(); j++)
			{
				if( j == 0 && seats[i][j] == 'Y')
				{
					max++;
					seats[i][j] = 'T';
				}
				else if(j > 0 && seats[i][j] =='Y' && seats[i][j-1]!='T')
				{
					max++;
					seats[i][j] = 'T';
				}
			}
		}
		return max;
		
	}
	

	
	
	
		       
};
 
int main()
{
      	VeryInterestingMovie a;
	int l;
	string complearr[] =  {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );
	l = a.maximumPupils(comple);
	cout << l;

	
}
