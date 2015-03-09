#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class QuickSums // started 8 50                                                                                                   
{
  public:

        int minSums(string numbers, int sum)
        {
                int ans = numeric_limits<int>::max();
                if(strtoi(numbers)==sum) // The initial string is the sum                                                         
                        return 0;
                int length = numbers.size()-1;
                for (int s = 1; s < (1 << length); ++s)    // iterate through all non-null sets                                   
                {
                        vector<int> check(length,0);
			for (int e = 0; e < length; ++e)       // for each set element                                            
                        {
                                if (s & (1 << e))                     // test for membership of set                               
                                {
                                        check[e] = 1;
                                }
                        }
                        int pluses = checkPlus(check,sum,numbers);
                        ans = min(ans,pluses);
                }
		if(ans == numeric_limits<int>::max())
			return -1;
                return ans;
	}


 	int checkPlus(vector<int> v, int sum, string numbers)
        {
                int tot = 0;
                int lastplus = 0;
                int cnt = 0;
                for(int i = 0; i < v.size(); i++)
                {
                        if(v[i] == 1)
                        {
                                //int c = strtoi(numbers.substr(lastplus, (i+1)-lastplus));                                       
                                tot+=strtoi(numbers.substr(lastplus, (i+1)-lastplus));
                                lastplus = i+1;
				cnt++;
                                if(tot>sum)
                                        return numeric_limits<int>::max();
                        }
                }
                tot+= strtoi(numbers.substr(lastplus));
                if(tot == sum)
		{
                        return cnt;
                }
                else
		{
                 	return numeric_limits<int>::max();
                }


	}

        int strtoi(string str)
	{
                return atoi(str.c_str());
	}


	void printVec(vector<int> v)
        {
                for(int i = 0; i < v.size(); i++)
                        cout << v[i] << " ";

                cout << endl;
        }



};

/*int main()
{
 	QuickSums a;

	int v = a.minSums("123",123);
	cout << v;

}*/

