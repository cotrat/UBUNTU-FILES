#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <climits>
using namespace std;


class ColorfulRabbits
{
  public:


	int getMinimum(vector<int> inp)
	{
		int amt = 0;
		vector<int> done(inp.size(),0);
		for(int i = 0; i < inp.size(); i++)
		{
			int cnt = inp[i];
			bool share = 0;
			if(done[i] == 1)
			{
					//cout << "We have already used index " << i << "which is value " << inp[i] << endl;
					continue;
			}
			for(int j = i+1; j < inp.size(); j++)
			{
			
				if(cnt == 0)
				{
					share = 1;
					break;
				}
				//cout << "compare " << i << " and " << j << endl;
				if(inp[i]==inp[j])
				{
					//cout << "indexes " << i << " and " << j << " are eq " << endl;
					done[j] = 1;
					cnt--;
				}
			}
			if(share==1)
			{
				amt+= (inp[i]+1);
			}
			else if(done[i]!=1)
			{
				amt+= (inp[i]+1);
			}
		}	
		return amt;
	}

	
	
	
		
		       
};
 
/*int main()
{
      	ColorfulRabbits a;
	int complearr[] =  	{2, 2, 44, 2, 2, 2, 444, 2, 2 };
	vector<int> arr(complearr,complearr + sizeof(complearr) / sizeof(int) );
	int v = a.getMinimum(arr);
	cout << v;

}*/
