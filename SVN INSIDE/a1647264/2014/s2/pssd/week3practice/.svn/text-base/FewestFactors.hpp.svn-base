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

class FewestFactors // started 5 39 finish 6 16
{
  public:
	int number(vector<int> digits)
	{
		sort(digits.begin(), digits.end());
		int min;
		int min_current;
		int min_num_factors = numeric_limits<int>::max(); // set to a very large value
		do 
		{
			string str;
			stringstream ss;
    			for( int i = 0; i < digits.size(); i++)
			{
				
				ss << digits[i];
			}
			min_current = atoi(ss.str().c_str());
			int num_factors = calcFactors(min_current,min_current,0);
			//cout << min_current << " has " << num_factors << endl;
			if(num_factors < min_num_factors)
			{
				min_num_factors = num_factors;
				min = min_current;
			}
		} while (next_permutation(digits.begin(), digits.end()));

		return min;
	}

	int calcFactors(int n, int nless, int count)
	{
		//cout << "try " << n << " modulo " << nless << endl;
		if( nless == 0 )
		{
			return count;
		}

		if( n % nless == 0 )
		{
			calcFactors(n,nless-1,count+1);
		}
		else
		{
			calcFactors(n,nless-1,count);
		}
	}
	
        
 
};
 
/*int main()
{
      	FewestFactors a;
	vector<int> vec;
	vec.push_back(7);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(4);
	a.number(vec);
	//int l = a.calcFactors(12,12,0);
	//cout << l;       
}*/
