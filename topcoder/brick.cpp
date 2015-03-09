#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class TheBrickTowerEasyDivOne
{
  public:
	

	int find(int rc, int rh, int bc, int bh)
	{
		int maxh; // how many evens we can make
		int evens;
		int odds;
		int mini = min(rc,bc);
		if(rh == bh)
		{
			if(rc == bc)
				return mini*2;
			return mini*2 + 1;
		}
		else if(rc == bc)
		{
			maxh = (mini*2); // how many evens we can make
			evens = maxh/2;
			odds = maxh-evens;
			return evens+(2*odds);
		}
		else
		{
			maxh = (mini*2); // how many evens we can make
			evens = maxh/2;
			odds = maxh-evens;
			return evens+(2*odds)+1;
		}
	}
	

	
	
	
		       
};
 
int main()
{
      	TheBrickTowerEasyDivOne a;
	int v = a.find(4,4,4,7);
	cout << v;

	
}
