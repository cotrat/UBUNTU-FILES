#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <utility>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <bitset>
using namespace std;

//http://community.topcoder.com/stat?c=problem_statement&pm=10511

class TheNewHouseDivTwo // Completed and Working 
{
  public:
	int count(vector<int> x, vector<int> y)
	{
		vector<pair<int,int> > coords;
		for(int z = 0; z < x.size(); z++)
		{
			coords.push_back(make_pair(x[z],y[z]));
		}
		int ret = 0;
		int cnt;
		for(int i = -99; i < 100; i ++)
		{
			for(int j = -99; j < 100; j++)
			{
				bool left = 0,right = 0,up = 0,down = 0;
				for(int l = 0; l < coords.size(); l++)
				{
					if( coords[l].first < j && coords[l].second == i && !left)
						left = 1;
					if( coords[l].first > j && coords[l].second == i && !right)
						right = 1;

					if( coords[l].first == j && coords[l].second < i && !down)
						down = 1;
					if( coords[l].first == j && coords[l].second > i && !up)
						up = 1;	
				}
				if(up && down && left && right)
					ret++;
			}
		}
		return ret;

	}

	

	
	
	
		       
};
 
int main()
{
      	TheNewHouseDivTwo a;


	int arr[] = {91, 91, 93, 91, 93, 100, 92, 95, 97, 98, 99, 99, 96, 91, 99, 97, 91, 97, 92, 99, 95, 96, 99, 95, 95, 93, 93, 93, 96, 96, 92, 95, 100, 91, 98, 91, 92, 93, 97, 95, 93};
	vector<int> x(arr,arr + sizeof(arr) / sizeof(int) );

	int arr2[] = {96, 94, 91, 94, 100, 91, 91, 91, 93, 91, 95, 91, 91, 91, 97, 91, 91, 92, 94, 91, 95, 91, 95, 91, 99, 91, 94, 96, 91, 91, 96, 99, 97, 97, 91, 91, 96, 91, 99, 91, 99};
	vector<int> y(arr2,arr2 + sizeof(arr2) / sizeof(int) );


	int l = a.count(x,y);
	cout << l;

	
}
