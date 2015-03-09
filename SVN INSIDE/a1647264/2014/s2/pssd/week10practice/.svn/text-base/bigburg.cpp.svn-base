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


class BigBurger
{
  public:
	


	int maxWait(vector<int> arrival, vector<int> service)
	{
		vector<int> actualBegins;

		int currentTime = arrival[0]+service[0];
		int maxDist = -1;
		for(int i = 1; i < service.size(); i++)
		{
			if(currentTime < arrival[i]) currentTime = arrival[i];
			if(currentTime-arrival[i] > maxDist) maxDist = currentTime-arrival[i];
				//cout << "PERSON " << i <<  " actually starts at " << currentTime << " instead of " << arrival[i] << endl;
			
			currentTime += service[i];
		}

		
		return maxDist;
	}
	
	
	
	
	
	
		       
};
 
int main()
{
      	BigBurger a;
	int l;
	int complearr[] =   	 	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );

	int complearr2[] =   	{15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};
	vector<int> comple2(complearr2,complearr2 + sizeof(complearr2) / sizeof(int) );
	l = a.maxWait(comple,comple2);
	cout << l;

	
}
