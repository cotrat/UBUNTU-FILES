#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;
// Completed in 10 minutes

class StrangeComputer
{
  public:
	int setMemory(string mem)
	{
		int count = 0;
		string mem2 (mem.length(), '0'); // set string length of input all 0's
		for(int i = 0; i < mem.length(); i++)
		{
			if(mem2[i]!=mem[i]) // if not equal
			{
				count++;
				for(int j = i; j < mem2.length(); j++)
				{
					mem2[j] = mem[i];
				}
				
			}	
		}	
		return count;
	}
	
        
 
};
 
/*int main()
{
      	StrangeComputer a;
	a.setMemory("0101010101010101010101010101010101010101010101011");
	       
}*/
