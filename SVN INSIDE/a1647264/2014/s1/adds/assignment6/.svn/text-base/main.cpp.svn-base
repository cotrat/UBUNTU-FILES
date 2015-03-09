// Design began 03/05/2014
// Coding Began 03/05/2014

#include "binaryNode.h"
#include "Individual.h"
#include "BitFlip.h"
#include "Rearrange.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	vector<string> inputs;
	string entries;
	getline(cin, entries);
    	istringstream entryStream(entries); 


	// Storing the inputs in vector
	do
    	{
        	string word;
        	entryStream >> word; 
		inputs.push_back(word);
    	} while (entryStream); 

	int value = atoi(inputs[1].c_str());
	int value2 = atoi(inputs[3].c_str());

	Individual *myLink = new BitFlip(inputs[0]);
	myLink->execute(value);
	cout << myLink->getString();
	
	cout << " ";

	Individual *myLink2 = new Rearrange(inputs[2]);
	myLink2->execute(value2);
	cout << myLink2->getString();

	delete myLink2;
	delete myLink;

	
}
