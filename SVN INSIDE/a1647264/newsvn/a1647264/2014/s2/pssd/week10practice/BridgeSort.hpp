#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
#include <queue>
#include <utility>
using namespace std;


class BridgeSort
{
  public:
	


	string sortedHand(string hand)
	{
		vector<pair<string,int> > cards;
		for(int i = 0; i <= hand.size()-2; i+=2)
		{
			string s1 = hand.substr(i,1);
			string s2 = hand.substr(i+1,1);
			int n2;
			n2 = atoi(s2.c_str());
			if(s2 == "T")
			{
				n2 = 10;
			}
			if(s2 == "J")
			{
				n2 = 11;
			}
			if(s2 == "Q")
			{
				n2 = 12;
			}
			if(s2 == "K")
			{
				n2 = 13;
			}
			if(s2 == "A")
			{
				n2 = 14;
			}
			
			cards.push_back(make_pair(s1,n2));
			
			
		}
		sort(cards.begin(), cards.end());
		string ans;
		for(int j = 0; j < cards.size(); j++)
		{
			//cout << cards[j].first << cards[j].second << endl;
			string p1 = cards[j].first;
			ostringstream ss;
			ss<<cards[j].second;
			string p2 = ss.str();
			if(p2 == "10")
			{
				p2 = "T";
			}
			if(p2 == "11")
			{
				p2 = "J";
			}
			if(p2 == "12")
			{
				p2 = "Q";
			}
			if(p2 == "13")
			{
				p2 = "K";
			}
			if(p2 == "14")
			{
				p2 = "A";
			}
			ans+= p1+p2;
		}
		return ans;
	}
	
	
	
	
	
	
		       
};
 
/*int main()
{
      	BridgeSort a;
	string l;

	l = a.sortedHand("H3SAHA");
	cout << l;

	
}*/
