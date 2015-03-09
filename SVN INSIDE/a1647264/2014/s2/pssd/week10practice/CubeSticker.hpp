#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <map>
#include <sstream>
#include <queue>
using namespace std;


class CubeSticker
{
  public:	
	string isPossible(vector<string> sticker)
	{
		int ans = 0;
		map<string,int> stickerCounts;
		for(int i = 0; i < sticker.size(); i++)
		{
			stickerCounts[sticker[i]]++; 
		}
		map<string,int>::iterator iter;
		for(iter = stickerCounts.begin(); iter!=stickerCounts.end(); iter++)
		{
			ans+=min(iter->second,2);
		}

		if(ans>=6) return "YES";
		return "NO";
	}
	
	
	
	
	
	
		       
};
 
/*int main()
{
      	CubeSticker a;
	string l;
	string complearr[] = {"purple","orange","orange","purple","black","orange","purple"};
	vector<string> comple(complearr,complearr + sizeof(complearr) / sizeof(string) );

	l = a.isPossible(comple);
	cout << l;

	
}*/
