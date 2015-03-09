#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class ProblemsToSolve
{
  public:
	

	int minNumber(vector<int> ples, int variance)
	{
		int ans = ples.size();
		int d1;
		int d2;
		int mini = 999999999;
		for(int i = 0; i < ples.size(); i++)
		{
			for(int j = i + 1; j < ples.size(); j++)
			{
				if( abs(ples[i] - ples[j]) >= variance)
				{
					//cout << i << "    " << j << endl;
					int d1 = 1 + (i+1) / 2;
					int d2 = (j - i + 1) / 2;
					mini = min(mini,(d1+d2));
				}
			} 
		}
		if(mini > ples.size()) return ples.size();
		return mini;
	}
	

	
	
	
		       
};
 
/*int main()
{
      	ProblemsToSolve a;

	int complearr[] =  {6,2,6,2,3,3,3,7};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );
	cout << a.minNumber(comple,4);
	
	
}*/
