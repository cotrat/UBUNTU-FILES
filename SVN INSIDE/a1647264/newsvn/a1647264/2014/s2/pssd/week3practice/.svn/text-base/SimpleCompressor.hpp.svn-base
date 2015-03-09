#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>
#include <sstream>
using namespace std;
 

 
class SimpleCompressor
{
  public:
	
        string extend(string str, int n)
	{
		string newstr;
		for(int i=0; i < n; i++)
		{
			newstr.append(str);
		}
		return newstr;
	}
	int brackmatch(string str)
	{
		vector<int> pos(str.length(),0); 
		bool left = 0;
		int ctr = 0;
		for(int i = 0; i < str.length(); i++)
		{
			//cout << " checking " << str[i];
			if(str[i] == '[')
			{
				left = 1;
				ctr++;
			}
			if(str[i] == ']')
			{
				left = i;
				ctr--;
			}
			if((ctr == 0) and (left == 1))
			{
				return i;
			}
		}
		return -1;
	}
        string uncompress(string toCompress)
        {
		// Find and occurence of a '['
		//cout << "call was on " << toCompress << endl;
		int last = brackmatch(toCompress);
		
		int first = toCompress.find("[");
		//cout << last << " " << first << endl;
		if(last == -1) // We either need to multiply, or return because we are done
		{
			if(isdigit(toCompress[0])) // We found a digit and need to multiply
			{
				int amt = toCompress[0] - '0';
				return extend(toCompress.substr(1), amt);
			}
			else
			{
				//cout << toCompress;
				return toCompress;
			}
			
			
		}
		else
		{
			string inbetween = toCompress.substr(first+1,(last-first)-1);
			///*string un = */toCompress.insert(first, inbetween);
			//cout << "will call on " << inbetween << endl;
			return uncompress(toCompress.substr(0,first)+uncompress(inbetween)+toCompress.substr(last+1));
		}	
		
        }      
 
};
 	//CABABABABABABC
	//CABABABABABABC

	//KUWWFAYFAYWWFAYFAYWWFAYFAYWWFAYFAYZBWWWWWWNCJJTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOYOOOOOOOOOOOOOOOOOOOOOOOOOOOFJL
	//KUWWFAYFAYWWFAYFAYWWFAYFAYWWFAYFAYZBWWWWWWNCJJTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOTPTYHQOTYHQOTYHQOTYHQOTYHQOTYHQOYOOOOOOOOOOOOOOOOOOOOOOOOOOOFJL
/*int main()
{
        SimpleCompressor A;
	string l = A.compressor("KU[4WW[2FAY]]ZB[6W]NCJJ[3[5TP[6TYHQO]]]Y[9[3O]]FJL");
	cout << l;
	//int l = A.brackmatch("C[2[3AB]]");
	//cout << l;
       
}*/
