#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class PaternityTest
{
  public:


	vector<int> possibleFathers(string child, string mother, vector<string> fathers)
	{	
		int motheramt;
		vector<int> ans;
		for(int i = 0; i < fathers.size(); i++) // For every father
		{

			int amt = 0;
			bool possible = 1;
			for(int j = 0; j < fathers[i].size(); j++) // Check if he has half the childs sample
			{
				if(fathers[i][j]!=child[j] and mother[j]!=child[j])
				{	
					possible = 0;
					break;
				}
				else if(fathers[i][j]==child[j])
				{
					amt++;
				}
			}

			if(amt >= child.size()/2 and possible)
			{
				ans.push_back(i);
			}
		}
		return ans;
	}

	
		
		       
};
 
/*int main()
{
      	PaternityTest a;
	string complearr[] = {"ABCY", "ASTD", "QBCD"};
	vector<string> arr(complearr,complearr + sizeof(complearr) / sizeof(string) );

	a.possibleFathers("ABCD","ABCX",arr);
	
}*/
