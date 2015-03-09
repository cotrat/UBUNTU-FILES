#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class RunLengthDecoding
{
  public:

	string decode(string text)
	{	
		int value;
		string thenum;
		string str2;
		int lastchar = 0;
		for(int i = 0; i < text.size(); i++)
		{
			
			thenum = "";
			if(!isdigit(text[i])) // If its a char get the preceeding numbers
			{
				thenum = text.substr(lastchar,i-lastchar);
				lastchar = i+1;
				if(thenum!="")
				{
					value = atoi(thenum.c_str());
				}
				else
				{
					value = 1;

				}
				if(str2.size() + value > 50)
					return "TOO LONG";
				for(int j = 0; j < value; j++)
				{
					str2+=text[i];
				}

			}		
		}
		return str2;
	}

	
		
		       
};
 
/*int main()
{
      	RunLengthDecoding a;
	string f = a.decode("21Z13S9A8M");
	cout << f;
}*/
