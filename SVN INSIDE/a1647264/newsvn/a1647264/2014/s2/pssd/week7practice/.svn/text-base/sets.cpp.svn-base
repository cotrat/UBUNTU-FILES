#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class PrefixFreeSets
{
  public:
	

	int maximumPupils(vector<string> words)
	{
		int max = 0;
		int cnt;
		sort(words.begin(), words.end());
		string prevstart = words[0];
		do 
		{
			if(words[0] == prevstart)
			{
				prevstart = words[0];
				continue;
			}
	 		cnt = 0;
			for(int i = 0; i < words.size(); i++)
			{

				bool nonpre = 1;
				for(int j = 0; j < words.size(); j++)
				{
					if(i==j) continue;
					bool prefixed = words[j].find( words[i] ) == 0;

					if(prefixed)
					{
						nonpre = 0; // it is a prefix of some other word in the set
						break;
					}
	
				}
				if(nonpre)
					cnt++;

			}
			if(cnt>max)
				max = cnt;
			
		} while (next_permutation(words.begin(), words.end()));
		cout << max;
		return 1;
	}
	

	
	
		       
};
 
int main()
{
      	PrefixFreeSets a;
	int l;
	string complearr[] =  {"h", "hi", "hiiii", "ahf", "gjeo", "fpaojep", "lallaa", "la", "lala", "alala", "fe", "feeed", "feeding", "feeding"};
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );
	l = a.maximumPupils(comple);
	//cout << l;
	//a.countMax(comple);

	
}
