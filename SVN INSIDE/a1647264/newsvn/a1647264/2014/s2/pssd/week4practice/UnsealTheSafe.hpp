#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class UnsealTheSafe // started 8 50
{
  public:
	
	vector<vector<long long> > dynamic;	

	long long countPasswords(int n)
	{
		for(int i = 0; i < 10; i++)
		{
			vector<long long> vec;
			for(int j = 0; j < 31; j++)
			{
				vec.push_back(-1); // initialise all -1
			}
			dynamic.push_back(vec);
		}
		long long sum = 0;
		for(int ii = 0; ii < 10; ii++)
		{
			long long dig = recur(ii,n);
			//cout << "which has a result of" << dig;
			sum = sum + dig;
			cout << endl;
		}
		return sum;	
	}

	long long recur(int curr, int num)
	{
		long long tmp;
		if(dynamic[curr][num] > 0)
		{		//if we have already calculated dont do it again
			//cout << "did it dynamically " << endl;
			return dynamic[curr][num];
		}
		if(num==1)
			return 1;
		
		switch(curr)
		{
			case 0:
				tmp = recur(7,num-1);
				break;
	  		case 1:
				tmp = recur(2,num-1) + recur(4,num-1);
				break;
			case 2:
				tmp = recur(1,num-1) + recur(3,num-1) + recur(5,num-1);
				break;
			case 3:
				tmp = recur(2,num-1) + recur(6,num-1);
				break;
			case 4:
				tmp = recur(1,num-1) + recur(5,num-1) + recur(7,num-1);
				break;
			case 5:
				tmp = recur(2,num-1) + recur(4,num-1) + recur(6,num-1) + recur(8,num-1);
				break;
			case 6:
				tmp = recur(5,num-1) + recur(3,num-1) + recur(9,num-1);
				break;
			case 7:
				tmp = recur(4,num-1) + recur(8,num-1) + recur(0,num-1);
				break;
			case 8:
				tmp = recur(5,num-1)+recur(7,num-1) + recur(9,num-1);
				break;
			case 9:
				tmp = recur(6,num-1) + recur(8,num-1);
				break;
			
  		}
		dynamic[curr][num] = tmp;
		return tmp;
	}
	
        
 
};
 
/*int main()
{
      	UnsealTheSafe a;
	long sum = 0;
	sum = a.CountPasswords(30);
	cout << sum;
	

}*/
