#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <sstream>
using namespace std;


class RGBStreet 
{
  public:

	vector<string> answers;
	int max_pos;
	int estimateCost(vector<string> houserow)
	{

		// GET ALL COSTS
		vector<vector<int> > costs;

		for(int ii =0; ii < houserow.size(); ii++)
		{
			vector<int> cost2;
			istringstream iss(houserow[ii]);
			do
	    		{
				
				int amt;
				iss >> amt;
				cost2.push_back(amt);
	    		} while (iss);
			costs.push_back(cost2);

		}
		////////////////////////////

		max_pos = houserow.size()-1;
		int min = numeric_limits<int>::max();
		recur("",0);
		
		
		for(int i = 0; i < answers.size(); i++)
		{
		
			int curr = 0;
			
			for(int j = 0; j < answers[i].size(); j++)
			{
			
				if(answers[i][j] == 'R')
					curr+=costs[j][0];
				if(answers[i][j] == 'G')
					curr+=costs[j][1];
				if(answers[i][j] == 'B')
					curr+=costs[j][2];
			}
			if(curr<min)
				min = curr;
			//cout << answers[i] << endl;
		}
		return min;
	}

	

	void recur(string houses, int pos)
	{
		// Condition that no two neighbouring houses can be the same colour
		
		if(pos>1) // Check that the previous house isnt the same
		{
			//cout << "this is the string " << houses << endl;
			//cout << "CHECK IF " << houses[pos-2] << " IS " << houses[pos-1] << endl;
			if(houses[pos-2] == houses[pos-1])
			{
				//cout << "cutoff" << endl;
				return;
			}
		}
		
		if(pos>max_pos)
		{
			answers.push_back(houses);
			return;
		}
		recur(houses+"R",pos+1);
		recur(houses+"G",pos+1);
		recur(houses+"B",pos+1);

	}
	
		       
};
 
int main()
{
      	RGBStreet a;
	string complearr[] = {"798 967 733", "68 475 124", "501 783 925", "598 635 790", "719 504 244", "437 439 926", "301 864 985", "713 576 850", "707 736 815", "259 474 915", "743 516 339", "813 190 793", "637 499 671", "6 302 691", "775 737 878", "618 449 516", "887 794 967", "450 463 307", "918 174 93", "15 308 345"};
	vector<string> arr(complearr,complearr + sizeof(complearr) / sizeof(string) );	
	int l = a.estimateCost(arr);
	cout << l;


	

	
	
	

}
