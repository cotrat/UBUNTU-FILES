#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <limits>
using namespace std;

 
class SentenceDecomposition
        {
        public:

	int amount(string s1,string s2)
	{
  		string s11 = s1;			// need to save strings because we need the originals
		string s22 = s2;
		sort(s11.begin(), s11.end());
		sort(s22.begin(), s22.end());
		if(s11!=s22) return 100000000;		// strings must be the same
		int cnt = 0;
		for(int i = 0; i < s1.size(); i++)
		{
			if(s1[i]!=s2[i]) cnt++;		// check how many we need to change
		}
		return cnt;
	} 

        int decompose(string sentence, vector <string> valid)
        {
		int dp[51];	
		
		for(int i= 0; i <= sentence.size();i++)
		{
			dp[i] = 100000000;
		}

		dp[0] = 0;
		for(int j = 1; j <= sentence.size(); j++)	// for each string length (e.g 0-1, 0-2)
		{
			for(int k = 0; k < j; k++)
			{
				for(int l = 0; l < valid.size(); l++)
				{
					dp[j] = min(dp[j], dp[k]+amount(valid[l],sentence.substr(k,j-k)));  // find the best way to get to this point in the string
				}
			}
		}
		if (dp[sentence.size()]==100000000)
			return -1;

		return dp[sentence.size()];
        }
        

}; 
 
/*int main()
{
      	SentenceDecomposition a;

	string complearr[] = {"one", "two", "three", "there"};
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );
	int l = a.decompose("neotowheret",comple);
	cout << l;
	

	
}*/
