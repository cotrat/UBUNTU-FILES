#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;


class Reppity
{
  public:
  int longestRep(string input)
  {
	int longest = 0;
	for( int i = 0; i <= input.length(); i++)
	{
		for (int j = 1; i+j <= input.length(); j++)
		{
			string current = input.substr(i,j);
			string search = input.substr(i+j);
			int found = search.rfind(current);
			
			if((found >= 0) and (current.length() > longest))
			{
				longest = current.length();
			}
	
			
		}
	}
	return longest;
  }
};


