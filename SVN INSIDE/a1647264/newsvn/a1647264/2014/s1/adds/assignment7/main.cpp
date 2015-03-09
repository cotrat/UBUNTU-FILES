//DESIGN BEGAN 10-05-14
//CODING BEGAN 11-05-14

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
using namespace std;

int main()
{
	vector<int> inputs;
	string entries;
	getline(cin, entries);
  	istringstream iss(entries);
	int val;
  	while (iss >> val)
  	{
		inputs.push_back(val);
  	}

	//BubbleSort myb; Bubble sort ready to use, but not called
	//myb.exec(inputs);
	QuickSort myq;
	myq.exec(inputs, 0, inputs.size() - 1);

	RecursiveBinarySearch mybin;
	int found = mybin.bSearch(inputs, 0, 0, inputs.size() - 1);
	if (found >= 0)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}

	for(unsigned int i = 0; i < inputs.size(); i++)
	{
		cout << " " << inputs.at(i);
	}
}
