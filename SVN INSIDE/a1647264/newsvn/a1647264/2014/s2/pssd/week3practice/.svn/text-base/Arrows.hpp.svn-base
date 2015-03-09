#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class Arrows // started 8 50
{
  public:
	int longestArrow(string s)
	{
		int maxlen = -1;
		int j;
		int arrowlen = -10;
		char arrow;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '<') // we need to check right
			{
				if(i+1 >= s.length()) // gone off the edge
				{
					arrowlen = 1;
					continue;
					
				}
				else if(s[i+1] == '=')
				{
					//cout << " an equals arrow was found beginning at " << i << endl;
					arrow = '=';
					arrowlen = 1;
					j = i+1;
				}
				else if(s[i+1] == '-')
				{
					//cout << " a dash arrow was found beginning at " << i << endl;
					arrow = '-';
					arrowlen = 1;
					j = i+1;
				}
				else
				{
					//cout << "should hit this " << endl;
					arrowlen = 1;
					continue;	
				}

				while((s[j] == arrow) && (j < s.length()))
				{
					//cout << "compare " << s[j] << "against " << arrow << endl;
					arrowlen++;
					j++;
				}
			}


			if(s[i] == '>') // we need to check left
			{
				if(i-1 < 0) // gone off the edge
				{
					arrowlen = 1;
					continue;
				}
				else if(s[i-1] == '=')
				{
					//cout << " an equals arrow was found beginning at " << i << endl;
					arrow = '=';
					arrowlen = 1;
					j = i-1;
				}
				else if(s[i-1] == '-')
				{
					//cout << " a dash arrow was found beginning at " << i << endl;
					arrow = '-';
					arrowlen = 1;
					j = i-1;
				}
				else
				{
					arrowlen = 1;
					continue;	
				}

				while((s[j] == arrow) && (j >= 0))
				{
					//cout << "compare " << s[j] << "against " << arrow << endl;
					arrowlen++;
					j--;
				}
			}


			if(arrowlen > maxlen)
			{
				maxlen = arrowlen;
			}
		}

		if(arrowlen > maxlen)
		{
			maxlen = arrowlen;
		}
		return maxlen;
	}
	
        
 
};
 
/*int main()
{
      	Arrows a;
	int l = a.longestArrow("----==-");
	cout << l;
	
	
}*/
