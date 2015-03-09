#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class FriendlySequences // Started 4 42 completed 5 35
{
  public:
	vector<string> itos(vector<int> ints)
	{
		vector<string> ret;
		for(int i = 0; i < ints.size(); i++)
		{
			stringstream ss;
			ss << ints[i];
			ret.push_back(ss.str());
			
		}
		return ret;
	}

	bool comp_str(string a, string b)
	{
		string longstr;
		string shortstr;
		if(a.length() > b.length())
		{
			longstr = a;
			shortstr = b;
		}
		else
		{
			longstr = b;
			shortstr = a;
		}
		
		vector<int> anums(10,0);
		vector<int> bnums(10,0);
		for(int i = 0; i < longstr.length(); i++)
		{
			anums[longstr[i]-'0'] = 1; // that number exists
		}

		for(int j = 0; j < shortstr.length(); j++)
		{
			bnums[shortstr[j]-'0'] = 1; // that number exists
		}

		for(int k = 0; k < 10; k++)
		{
			if(bnums[k]!=anums[k])
				return 0;
		}
		return 1;

	}

	int count(vector<int> array)
	{
	
			int ret = 0;
			vector<string> strings = itos(array);
			for(int i = 0; i < strings.size(); i++)
			{
				for(int j = i+1; j < strings.size(); j++)
				{
					//cout << "compare " << strings[i] << "to  " << strings[j] << endl;
					if(comp_str(strings[i],strings[j]))
					{
						ret++;
						//cout << "thats a hit " << endl;
					}
					else
					{
						break;
					}
				}
			}
			return ret;
	}
		       
};
 
/*int main()
{
      	FriendlySequences a;
	int complearr[] = {10, 1100, 10101, 111, 1111, 11111, 11, 1, 111};
	vector<int> arr(complearr,complearr + sizeof(complearr) / sizeof(int) );

	int l = a.count(arr);	
	cout << l;
	
		
	/*for(int i = 0; i < strings.size(); i++)
	{
		cout << strings[i] << endl;
	}

	
	
	

}*/
