#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class RockStar
{
  public:
	

	int getNumSongs(int ff, int fs, int sf, int ss)
	{
		int ans = 0;
		if( ff > 0 or fs > 0)
		{
			ans+= ff; 			// Add all of ff
			if(fs > 0)
			{
				ans+=min(fs,sf)*2;	// Add the "combo"

				if(fs > sf)
				{
					ans++;			// Extra 
				}
				ans += ss;
			}
	
			
			
		}
		else
		{
			ans += ss;
			if(sf > 0)
				ans++;
		}
		return ans;
	}
	

	
	
	
		       
};
 
/*int main()
{
      	RockStar a;
	int l = a.getNumSongs(141,1,505,63);
	cout << l;

	
}*/
