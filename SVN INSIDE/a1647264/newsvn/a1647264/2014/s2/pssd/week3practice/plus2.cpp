#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <sstream>
using namespace std;
 
/*
 string a = "1";
 string b= "2";
 int c = atoi(a.c_str())+atoi(b.c_str());
 cout << "result is " << c << endl;
*/
 int ctr = 0;
class Plus
{
  public:
	
        int strtoi(string str)
        {
                stringstream sstr(str);
                string sub;
                int sum = 0;
                while(getline(sstr, sub, '+'))
                {
                        sum += atoi(sub.c_str());
                }
                return sum;
        }

	/*int go(string nums,int pluses,int val)
	{
		int numsi = atoi(nums.c_str())
		if(nums == val)
		{
			return pluses; // if they sum up we have found it
		} 
		else if(val < 10) // if val is less than 10 and we havent found we cant find
		{
			return 0;
		}
		go(nums.substr(1),pluses+1,val-atoi(nums[0].c_str())) // else call it by moving across and adding a plus
	}*/

        int nextPlus(string p_string,int val)
        {
		vector<int> tests;
		
		for(int i = 0; i < p_string.length(); i++)
                {       
			cout << p_string.substr(i) << endl;
                }	
        }      
 
};
 
int main()
{
        Plus a;
        int l = a.strtoi("1+22+34+5");
        string p_string = "3824";
	string pstr;
        a.nextPlus(p_string,17);
	
       
}
