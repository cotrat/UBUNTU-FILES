#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class FairWorkload
{
  public:
	

	int getMostWork(vector<int> folders, int workers)
	{
		vector<int> spos;
		int min = 9999999999;
		for(int i = 0; i < workers; i++)
		{
			spos.push_back(folders.size()-i);
		}
		
		int curr = spos[0];
		while(curr!=1)
		{
			// get the sum of all the sets and find the min
		}
	}
	

	
	
	
		       
};
 
int main()
{
      	TaliluluCoffee a;
	int l;
	int complearr[] =  { 47, 46, 4, 12, 29, 20, 49};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );
	l = a.maxTip(comple);
	cout << l;

	
}
