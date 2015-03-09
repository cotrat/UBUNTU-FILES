#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class MatchNumbersEasy
{
  public:
	

	string maxNumber(vector<int> matches, int n)
	{
		string ans = "";
		int mini = 51;
		int digits;
		int to_make;
		for(int i = 1; i < matches.size(); i++)
		{
			if(matches[i] < mini)
			{
				mini = matches[i];
	
			}
		}

		if(mini < matches[0])
		{
			digits = n/mini;
			to_make = (digits - 1) * mini;
		}
		else
		{
			if(mini > n)
				return "0";
			digits = (n-mini)/matches[0];
			digits++;
			to_make = (digits - 1) * matches[0];
		}

		
		int soFar = 0;
		int will_use;
		while( soFar < digits)
		{
			//cout << "must keep " << to_make << "matches"<< endl;
			// Find the largest digit such that we are still above the to_make threshold
			for(int j = 0; j < matches.size(); j++)
			{
				if( n - matches[j] >= to_make )
				{
					will_use = j;
				}

			}
			
			ostringstream ss;
			ss<<will_use;
			string next = ss.str();
			ans+=next;



			//cout << " we will use the number " << will_use << " which uses " << matches[will_use] << endl;
			n = n - matches[will_use];		// We used this many matches
			//cout << "we now have " << n << "matches to use" << endl;
			to_make-=min(mini,matches[0]);
			
			soFar++;
		}
		//cout << "total digits " << digits << " min needed to make (digits - 1) " << to_make << endl;
		//cout << n;
		return ans;
		
	}
	

	
	
	
		       
};
 
/*int main()
{
      	MatchNumbersEasy a;
	
	int complearr[] = {1,5,3,2};
	vector<int> comple(complearr,complearr + sizeof(complearr) / sizeof(int) );
	cout << a.maxNumber(comple, 1);
	
	
	
}*/
