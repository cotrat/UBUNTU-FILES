#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class TaliluluCoffee
{
  public:
	

	int maxTip(vector<int> tips)
	{
		int ret = 0;
		sort(tips.begin(),tips.end(),greater<int>());
		for(int i = 0; i < tips.size(); i++)
		{
			if ((tips[i] - i) > 0) 
				ret += (tips[i] - i);
		}
		return ret;
	}
	

	
	
	
		       
};
 
/*int main()
{
      	TaliluluCoffee a;
	int l;
	int complearr[] =  { 47, 46, 4, 12, 29, 20, 49};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );
	l = a.maxTip(comple);
	cout << l;

	
}*/
