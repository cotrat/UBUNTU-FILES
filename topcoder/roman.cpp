#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <bitset>
using namespace std;


class Islands
{
  public:
	int beachLength(vector<string> s)
	{
		int beach = 0;
		for(int i = 0; i < s.size(); i ++)
		{
			for(int j = 0; j < s[0].size(); j++)
			{
				if(s[i][j]=='#')
				{
					if( j-1 >= 0 && s[i][j-1] == '.')
						beach++;
					if( j+1 < s[0].size() && s[i][j+1] == '.')
						beach++;
					if(i+1 < s.size() && s[i+1][j] == '.')
						beach++;
					if(i-1 >= 0 && s[i-1][j] == '.')
						beach++;


					if(i%2 == 0) // if even
					{	
						if(i+1 < s.size() && j-1 >= 0 && s[i+1][j-1] == '.')
							beach++;
						if(i-1 >= 0 && j-1 >= 0 && s[i-1][j-1] == '.')
							beach++;
					}
					else
					{
						if(i+1 < s.size() && j+1 < s[0].size() && s[i+1][j+1] == '.')
							beach++;
						if(i-1 >= 0 && j+1 < s[0].size() && s[i-1][j+1] == '.')
							beach++;
					}

				} 
			}
		}
		return beach;

	}

	

	
	
	
		       
};
 
int main()
{
      	Islands a;
	
	string arr[] = {"#...#.....",
 "##..#...#."};
	vector<string> mon(arr,arr + sizeof(arr) / sizeof(string) );


	int l = a.beachLength(mon);
	cout << l;

	
}
