//DESIGN BEGAN 23-05-14
//CODE BEGAN 24-05-14

#include "myStack.h"
#include "RPN.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	vector<string> inputs;
	string entries;
	getline(cin, entries);
  	istringstream iss(entries);
	string val;

	while (iss >> val)
  	{
		inputs.push_back(val);
  	}

	RPN* myRPN = new RPN(inputs);
	myRPN->execute();
	delete myRPN;
	
	
}
