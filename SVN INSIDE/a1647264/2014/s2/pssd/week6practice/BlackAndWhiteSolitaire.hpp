#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class BlackAndWhiteSolitaire 
{
  public:
	

	int minimumTurns(string cardFront)
	{
		int m1 = 0, m2 = 0;
		for(int i = 0; i < cardFront.size(); i++)
		{
			if( i % 2 == 0)
			{
				if(cardFront[i]=='W') m1++;
				else	m2++;
			}
			if( i % 2 == 1)
			{
				if(cardFront[i]=='B') m1++;
				else	m2++;
			}
		}
		
		return min(m1,m2);
	}
	

	
	
	
		       
};
 
/*int main()
{
      	BlackAndWhiteSolitaire a;
	int l = a.minimumTurns("BBWBWWBWBWWBBBWBWBWBBWBBW");
	cout << l;
	
}*/
