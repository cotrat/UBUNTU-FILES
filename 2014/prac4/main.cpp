#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "EfficientFibonacci.h"
#include "Palindrome.h"
using namespace std;


int fib(int x) {

	static int count=0;
    	count++;
	cout << count << endl;

    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fib(x-1)+fib(x-2);
}

int main()
{
    	
	vector<string> inputs(5);
	string reversed,isPal;
	int fibbed;
	int ctr=0;
	bool valid_word;
	string entries;
	getline(cin, entries); // Getting the string of entries
    	istringstream entryStream(entries); // Turning the string into a stringstream



	do
    	{
        	string word;
        	entryStream >> word; // Storing each word from the stream in the string 'word'
		inputs[ctr]=word; // Pushing back the words into our vector of inputs
		ctr++;
    	} while (entryStream); // While not reached the end of stringstream
	
	EfficientFibonacci myFib; // Creating an Efficient Fibonaci object
		


	if(inputs[1]!="")
	{
		valid_word = myFib.checkWord(inputs.at(1));
		if(valid_word) // Check the word is only digits
		{
			int val = atoi(inputs.at(1).c_str()); // Changing from str to int
			fibbed = myFib.ApplyEfficientFibonacci(val); // Run the Efficient Fibonacci algorithm
		}
	}
	
	if(inputs[0]!="")
	{
		Palindrome myPal; // Creat a palindrome object
		reversed = myPal.reverse(inputs.at(0)); // Reverse the input string
		if(myPal.isPalindrome(inputs.at(0))) // Check if it is a palindrome
		{
			isPal = "yes";
		}
		else
		{
			isPal = "no";
		}
	}


	
	if(inputs[1]=="" or !valid_word)
	{
		cout << reversed << " " << isPal << " " << "ERROR";
	}
	else
	{
		cout << reversed << " " << isPal << " " << fibbed;
	}
	
	
	
	

}
