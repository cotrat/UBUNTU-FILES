#include <cstdlib>
#include <string>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <climits>
using namespace std;


class GoodHours
{
  public:


	int howMany(string a, string b)
	{
			int count = 0;
			int num;
			while(a!=b)
			{
				if(goodTime(a))
				{
					count++;
					cout << "goodtime    ";
				}
				a = incTime(a);
				cout << a <<endl;
				
			}
			
			if( a == b  and goodTime(a))
				count++;	
			
			return count;
			
	}

	bool goodTime(string a)
	{
	

		if( (a[0] - '0')*(a[1] - '0') == (a[3] - '0')*(a[4] - '0') )
		{
			return 1;
		}
		
		if( (a[0] - '0')*(a[1] - '0')*(a[3] - '0') == (a[4] - '0') )
		{
			return 1;
		}

		if( (a[4] - '0')*(a[3] - '0')*(a[1] -'0' ) == (a[0] - '0') )
		{
			return 1;
		}
		return 0;
	}
	string incTime(string a)
	{
		stringstream ss;
		string str;
		int num;
		if( (atoi(a.substr(0,2).c_str()) == 23) and (atoi(a.substr(3,2).c_str())==59) )
		{
			
			a[0] = '0';
			a[1] = '0';
			a[3] = '0';
			a[4] = '0';
		}
		else if( atoi(a.substr(0,2).c_str()) < 23 and atoi(a.substr(3,2).c_str())==59) // hours dont need to roll over, but do icnrease
		{
			num = atoi(a.substr(0,2).c_str())+1;
			ss << num;
			str = ss.str();
			if(str.size() < 2)
			{
				a[0] = '0';
				a[1] = str[0];
				a[3] = '0';
				a[4] = '0';
			}
			else
			{
				a[0] = str[0];
				a[1] = str[1];
				a[3] = '0';
				a[4] = '0';
			}
		}
		else
		{
			num = atoi(a.substr(3,2).c_str())+1;
			ss << num;
			str = ss.str();
			if(str.size() < 2)
			{
				a[0] = a[0];
				a[1] = a[1];
				a[3] = '0';
				a[4] = str[0];
			}
			else
			{
				a[0] = a[0];
				a[1] = a[1];
				a[3] = str[0];
				a[4] = str[1];
			}
			
		}
		return a;			
				
	}
		
		       
};
 
/*int main()
{
      	GoodHours a;
	int l = a.howMany("11:11","11:11");
	//cout << l;

}*/
