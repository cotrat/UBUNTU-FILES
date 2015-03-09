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
 	int strcount(string str)
	{
		int count = 0;
		for(int i = 0; i < str.length(); i++)
		{
			if(str[i] == '+')
				count++;
		}
		return count;
	}
        int nextPlus(string p_string,int val)
        {
		vector<int> pluses;
               	cout << " CALLING ON " << p_string << endl;
                if(strtoi(p_string) == val)
                {
                        cout << p_string << " Was the winning string ";// Find out how many pluses were in the string
			cout << strcount(p_string);
                        return strcount(p_string);
                }
                else if(p_string[p_string.length()-2] == '+')
                {
			cout << "plus in last pos end" << endl;
                        return 99999;
                        // if the last char is a plus then we are at the end and it hasnt been found
                }
 
                int last = p_string.rfind("+");
                /*if(last <= 0 )
                {
                        last = 0;
                }*/
		int end = abs(last);
		//cout << end;
		//cout << last;
		int length = p_string.length();
                for(int i = last; i < length-end+1; i++)
                {       
			if(i+2 < length)
			{  
				p_string.insert(i+2,"+") ;   
				nextPlus(p_string, val);
				p_string.erase(i+2,1); 
			}            
                        
                }
                //cout << "END OF " << ctr << "CALL" << endl;
		//ctr++;
		
        }      
 
};
 
int main()
{
        Plus a;
        int l = a.strtoi("1+22+34+5");
        string p_string = "3824";
	string pstr;
        a.nextPlus(p_string,17);
	/*for(int i = 2; i < 3; i++)
	{
		cout << p_string.insert(i+2,"+") << endl;
		p_string.erase(i+2,1);
	}
	//cout << p_string;*/
       
}
