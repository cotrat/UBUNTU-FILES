#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <sstream>
using namespace std;
 

class Plus
{
  public:
	
        /*int strtoi(string str)
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
 	int strcount(string str)
	{
		int count = 0;
		for(int i = 0; i < str.length(); i++)
		{
			if(str[i] == '+')
				count++;
		}
		return count;
	}*/

	void helper(string str, int itr)
	{
			int fixed = 0x01; // this is the fixed part
			int mask = 0x01; // these are the bits of the fixed part which matter
			for (int i=0; i<256; i++) {
			    if (i & mask == fixed) {
				cout<< i <<endl;
			    }
			}
			/*if(itr == 0)
			{
				cout << str << endl;
			}
			else
			{

				helper(str + "0", itr -1);
				helper(str + "1", itr -1);
			}*/
   	
	}

        int nextPlus(string p_string,int val)
        {
		helper("",3);	
        }      
 
};
 
int main()
{
        Plus a;
        int j = a.nextPlus("38234",17);
	
       
}
