#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class CountExpressions 
{
  public:
	

	int calcExpressions(int x, int y, int val)
	{
		int res = recur(0,x,y,1,2,x,val) + recur(0,x,y,2,1,y,val);
		
		return res;
	}
	

	int recur(int pos, int n1, int n2, int an1, int an2, int val, int des)
	{
		int cnt = 0;
		if(pos == 3 && val == des) // we made it
		{
			return 1;
		}
		else if(pos == 3)
		{
			return 0;
		}
		
		if(an1 > 0) // if we can use the first number
		{
			cnt += recur(pos+1,n1,n2,an1-1,an2,val+n1,des); // try plus
			cnt += recur(pos+1,n1,n2,an1-1,an2,val-n1,des); // try minus
			cnt += recur(pos+1,n1,n2,an1-1,an2,val*n1,des); // try mult
		}
		if(an2 > 0 ) // if we can use the second num
		{
			cnt += recur(pos+1,n1,n2,an1,an2-1,val+n2,des); // try plus
			cnt += recur(pos+1,n1,n2,an1,an2-1,val-n2,des); // try minus
			cnt += recur(pos+1,n1,n2,an1,an2-1,val*n2,des); // try mult
		}
		//cout << cnt << endl;
		return cnt;

	}

	
	
		       
};
 
/*int main()
{
      	CountExpressions a;
	int l = a.calcExpressions(	99, 100, 98010000);
	cout << l;
	
}*/
