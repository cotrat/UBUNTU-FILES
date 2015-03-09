#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class SimpleDuplicateRemover
{
  public:


	vector<int> process(vector<int> sequence)
	{
		if(sequence.size() == 1)
			sequence;
		vector<int> vals;
		vals.push_back(sequence[sequence.size()-1]);
		for(int j = sequence.size()-1; j >= 0; j--)
		{
			bool is = 0;
			for(int i = 0; i < vals.size(); i++)
			{
				if(vals[i] == sequence[j])
				{
					is = 1;
				}
			}
			if(!is) // If its not in there, put it in there
			{
				vals.push_back(sequence[j]);
			}
		}
		reverse(vals.begin(),vals.end());
		return vals;
	}
	
	
		
		       
};
 
/*int main()
{
      	SimpleDuplicateRemover a;
	int complearr[] = {5, 37, 375, 5, 37, 33, 37, 375, 37, 2, 3, 3, 2};
	vector<int> arr(complearr,complearr + sizeof(complearr) / sizeof(int) );

	vector<int> ans = a.process(arr);
	
		
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	

	

	
	
	

}*/
