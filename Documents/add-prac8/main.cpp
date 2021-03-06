#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

int main()
{	
	LinkedList *myLink = new LinkedList;

	vector<string> inputs;
	string entries;
	getline(cin, entries);
  	istringstream iss(entries);
	string val;
	string current_entry;

  	while (iss >> val)
  	{
		inputs.push_back(val);
  	}

	// Loop through all the inputs and add/remove nodes accordingly
	for (unsigned int i = 0; i < inputs.size(); i++)
	{
		current_entry = inputs.at(i);
		if (current_entry[0] == 'A' or current_entry[0] == 'a')
		{
			myLink->addNode(atoi(current_entry.substr(1).c_str()));
		}
		else if (current_entry == "R" or current_entry == "r")
		{
			myLink->removeNode();
		}
	}

	// Loop through all nodes and print their content
	if (myLink->getLength() > 0)
	{
		Node* current_node = myLink->getHead();
		for (int j = 0; j < myLink->getLength(); j++)
		{
			if (j < myLink->getLength()-1)
			{
				cout << current_node->value << "->";
			}
			else
			{
				cout << current_node->value << " ";
			}
			current_node = current_node->next;
		}
	}
	else
	{
		cout << "empty ";
	}

	myLink->getMiddle();
	

}
