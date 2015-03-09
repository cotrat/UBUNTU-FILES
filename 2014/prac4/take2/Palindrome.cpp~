#include "Palindrome.h"
#include <iostream>
#include <string>

using namespace std;

Palindrome::Palindrome()
{

}

Palindrome::~Palindrome()
{

}

bool Palindrome::isPalindrome(string palindrome)
{

    for(unsigned int i = 0;i < palindrome.length()/2; i++)
    {

        if(palindrome[i]!=palindrome[(palindrome.length()-1)-i]) // Iterating from front to middle and end to middle to see if the chars are identical
        {
            return 0;
        }
    }
    return 1;

}

string Palindrome::reverse(string to_rev)
{
    	if (to_rev.length() == 1 or to_rev.length() == 0) 
	{
        	return to_rev; // If the string is only length 1 or 0 return the string
    	}	
	else
	{
		string temp = to_rev.substr(1,to_rev.length()); // Creating a temporary string that is everything after the 1st letter
        	return reverse(temp) + to_rev[0];
    	}
}

