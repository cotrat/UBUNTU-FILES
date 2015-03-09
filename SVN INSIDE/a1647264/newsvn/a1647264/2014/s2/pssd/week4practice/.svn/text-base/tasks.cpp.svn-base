#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class ImportantTasks // started 4 25 completed 4 37
{
  public:

	int maximalCost(vector<int> complexity, vector<int> computers)
	{
			sort(computers.begin(), computers.end(), greater<int>()); // Sort computers in descending order
			sort(complexity.begin(), complexity.end(), greater<int>()); // Sort complex in descending order
			int ret = 0;
			int compitr = 0;
			for(int i = 0; i < complexity.size(); i++)
			{
				if(complexity[i] <= computers[compitr])
				{
					ret++;
					compitr++;
				}
				if(compitr > computers.size() - 1)
					return ret;

			}
			return ret;
	}
		       
};
 
int main()
{
      	ImportantTasks a;
	int complearr[] = {5,2,7,8,6,4,2,10,2,3};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );

	int compuarr[] = {4,1,3,6,2,10,11,1,1,3,4,2};
 	vector<int> compu(compuarr, compuarr + sizeof(compuarr) / sizeof(int) );


	int l = a.maximalCost(comple,compu);
	cout << l;
	
	
	

}
