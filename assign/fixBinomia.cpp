#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;


class Parse
{
  public:
	/**
	*	@param	- name of the file
	*	@return	- vector containing vectors
	*			- vector[0] = names of nodes
	*			- vector[1] = X co-ord
	*			- vector[2] = Y co-ord
	*			- vector[3] = Link.to
	*			- vector[4] = Link.from
	**/
	vector<vector<string> > parseInp(string filename)
	{
		ifstream fileReader(filename.c_str());		// Input stream			
		string line;								// String to containe each line

		int lineNum = 0;							// Store which line we are at
		string mode = "G";

		vector<vector<string> > returns;
		vector<string> nodeVec;
		vector<string> xVec;
		vector<string> yVec;
		vector<string> toVec;
		vector<string> fromVec;
		while(getline(fileReader,line))				// Read through each line in the text file
		{
			if(line == "Towns:") 					// Change to town parsing mode and skip the line "Towns:"
			{
				mode = "T";
				cout << "BELOW ARE THE TOWNS" << endl;
				continue;
			}
			else if(line == "Roads:") 				// Change to road parsing mode and skip the line "Roads:"
			{
				mode = "R";
				cout << "BELOW ARE THE ROADS" << endl;
				continue;
			}
			else if(line == "End")
			{
				mode = "G";
			}

			if(mode == "T")							// Begin Parsing towns
			{
				istringstream iss(line);
				string name;
				string x;
				string y;
				getline(iss, name, '(');
				getline(iss, x, ',');
				getline(iss, y, ')');
				cout << "Create a node called " << name << "(" << x << "," << y << ")" << endl; 
				nodeVec.push_back(name);
				xVec.push_back(x);
				yVec.push_back(y);
			}
			if(mode == "R")							// Begin Parsing roads
			{
				istringstream iss(line);
				string to;
				string from;
				getline(iss, to, '-');
				getline(iss, from, '>');
				getline(iss, from);
				cout << "Create a link " << to << "->" << from << endl;
				toVec.push_back(to);
				fromVec.push_back(from);
			}
			lineNum++;								// Increment the current lineNum
		}

		returns.push_back(nodeVec);
		returns.push_back(xVec);
		returns.push_back(yVec);
		returns.push_back(toVec);
		returns.push_back(fromVec);
		return returns;
	}
  
};

int main()
{
	Parse a;
	vector<vector<string> > ans;
	ans = a.parseInp("run1in.txt");
	for(int i = 0; i < ans[0].size()
}
