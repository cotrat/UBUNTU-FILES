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
		vector<int> spots;
		for(int i = 0; i < folders.size(); i++)
		{
			if(i < folders.size() - (workers - 1))
				spots.push_back(0);
			else
				spots.push_back(1);
			//cout << spots[i] << " "; '
		}
		int max = std::numeric_limits<int>::max();
		do 
		{	
			int val = calcMax(folders,spots);
			if(val < max)
			{
				max = val;
			}
			
		} while (next_permutation(spots.begin(), spots.end()));
		
		
		return max;
	}

	int calcMax(vector<int> folders, vector<int> spots)
	{
		int last = 0;
		vector<int> amt;
		for(int i = 0; i < spots.size(); i++)
		{
			int sum = 0;
			
			if(spots[i] == 1)
			{
				//cout << last << " to " << i-1 << " ";
				for(int j = last; j <= i-1; j++)
				{
					sum+=folders[j];
				}
				//cout << sum << " ";
				amt.push_back(sum);
				last = i;
			}

		}
		int sum2 = 0;
		for(int x = last; x < spots.size(); x++)
		{
			sum2+=folders[x];
		}
		//cout << endl<< endl<< endl << sum2 << endl << endl;
		//cout << endl << last << endl;
		amt.push_back(sum2);
		return *max_element(amt.begin(),amt.end());
		
	}
	

	
	
		       
};
 
/*int main()
{
      	FairWorkLoad a;
	int l;
	int complearr[] =  	{759, 746, 460, 92, 283, 739, 502, 501, 980, 86, 212, 276, 306, 571, 940};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );
	l = a.getMostWork(comple,8);
	cout << l;
	//a.countMax(comple);

	
}*/
