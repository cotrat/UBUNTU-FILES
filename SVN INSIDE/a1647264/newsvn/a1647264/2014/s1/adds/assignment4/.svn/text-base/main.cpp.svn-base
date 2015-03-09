// Design began: 05 04 14
// Coding began: 07 04 14
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "EfficientFibonacci.h"
#include "Palindrome.h"
using namespace std;

int main()
{
    	
	vector<string> inputs(5);
	string reversed,isPal;
	int fibbed=0;
	int ctr=0;
	bool valid_word=0;
	string entries;
	getline(cin, entries); 
    	istringstream entryStream(entries); 


	// Storing the inputs in vector
	do
    	{
        	string word;
        	entryStream >> word; 
		inputs[ctr]=word; 
		ctr++;
    	} while (entryStream); 
	
	EfficientFibonacci myFib; 
		


	if(inputs[1]!="")
	{
		valid_word = myFib.checkWord(inputs.at(1));
		if(valid_word) 
		{
			int val = atoi(inputs.at(1).c_str()); // Changing from str to int

			if(val > 46 or val < 0) // These conditions are set to check if integers are broken
			{
				valid_word = false;
			}
			if(valid_word)
			{
			fibbed = myFib.ApplyEfficientFibonacci(val);
			}
		}
	}
	
	if(inputs[0]!="")
	{
		Palindrome myPal;
		reversed = myPal.reverse(inputs.at(0)); 
		if(myPal.isPalindrome(inputs.at(0))) // Check if it is a palindrome return yes or no
		{
			isPal = "yes";
		}
		else
		{
			isPal = "no";
		}
	}


	
	if(inputs[1]=="" or !valid_word) // If the number is blank or invalid print ERROR instead
	{
		cout << reversed << " " << isPal << " " << "ERROR";
	}
	else
	{
		cout << reversed << " " << isPal << " " << fibbed;
	}
	


	
	

}
