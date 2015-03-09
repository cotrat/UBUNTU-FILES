#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <bitset>
using namespace std;


class SafeRemoval
{
  public:
	

	int removeThem()
	{
			/*for (int s = 0; s < (1 << 3); ++s)    // iterate through all non-null sets
   			{

				for (int e = 0; e < 3; ++e)       // for each set element
				{
		    			if (s & (1 << e))                     // test for membership of set
		    			{
		        			cout << "1";
		    			}
					else
					{
						cout << "0";
					}
					
	       			}
				cout << endl;
    			}*/

			int fixed = 0x01; // this is the fixed part
			int mask = 0x01; // these are the bits of the fixed part which matter
			for (int i=0; i<256; i++) {
			    if (i & mask == fixed) {
				cout<< i;
			    }
				cout << endl;
			}
	}
	

	
	
	
		       
};
 
int main()
{
      	SafeRemoval a;
	a.removeThem();


	
}
