#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <map>
#include <sstream>
#include <queue>
using namespace std;


class FoxAndMountainEasy
{
  public:	
	string possible(int n, int h0, int hn, string history)
	{
		int afterPath = 0;
		int pos = 0;
		int currLoc = h0;
		for(int i = 0; i < history.size(); i++)
		{
			if(history[i] == 'U') afterPath++;
			if(history[i] == 'D') afterPath--;
		}

		if( (currLoc + afterPath) < 0 )		// If negative
		{
			pos = abs(h0+afterPath);
			//cout << "To get back up we need " << pos << endl;
			
		}
		n-=pos;
		n-=history.size();
		//cout << "We have " << n << " Spots left to work with " << endl;
		currLoc += afterPath;
		currLoc += pos;
		//cout << "And we are now at " << currLoc << " Which means we need to travel " << abs(currLoc-hn) <<  endl;

		if( n == 0 )
		{
			//cout << "No way without going negative " << endl;
			return "NO";
		}

		if( n < abs(currLoc-hn))
		{
			//cout << "We needed to get to " << hn << " But we only had " << n << " Spots " <<endl;
			return "NO";

		}
		
		if( abs(currLoc-hn) % 2 ==  n%2 ) return "YES";		

	
		return "NO";
	}
	
	
	
	
	
	
		       
};
 
/*int main()
{
      	FoxAndMountainEasy a;
	string l;


	l = a.possible(36,52,70,"DDDDDDDDDDUUDDDDDDDDDDDDDDDDD");
	cout << l;

	
}*/
