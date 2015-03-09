#include "RPN.h"
#include <ctype.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

RPN::RPN(vector<string> input_values)
{
	values = input_values;
	the_stack = new myStack();
}

RPN::RPN()
{

}

RPN::~RPN()
{
	delete the_stack;
}

int RPN::execute()
{
	int oper1;
	int oper2;
	bool operator_present = 0;

	for(unsigned int j = 0; j < values.size(); j++)
	{
		if (check_operator(values[j]))
		{
			operator_present = 1;
		}
	}

	if(!operator_present && values.size() > 1) // If there is no operator present, and there is more than one entry, there is an error
	{
		cout << "Error";
		return -1;
	}

	// Iterate (from back-to-front) through the entries, push numbers in the stack
	// when an operator is found double pop the stack then compute the result

	for(int i = values.size() -1 ; i >= 0; --i)
	{
		if (check_num(values[i]))
		{
			the_stack->push(atoi(values[i].c_str()));
		}
		if (check_operator(values[i]))
		{
		
			if(i==0 and the_stack->size > 2)
			{
				cout << "Error"; //If the last place in the vector is an operator and there is more than 2 values left we cannot compute the third
				return -1;
			}

			oper1 = the_stack->pop();
			oper2 = the_stack->pop();

			if( values[i] == "+" )
			{
				the_stack->push(oper1+oper2);
			}
			else if( values[i] == "-" )
			{
				the_stack->push(oper1-oper2);
			}
			else if( values[i] == "*" )
			{
				the_stack->push(oper1*oper2);
			}
			else if( values[i] == "/" )
			{
				if(oper2 == 0)
				{
					cout << "Error"; 
					return -1;
				}
				the_stack->push(oper1/oper2);
			}

		}
	}

	cout << the_stack->pop();
	return -1;	
	
}

bool RPN::check_operator(string the_word)
{
	if (the_word == "*" or the_word == "/" or the_word == "+" or the_word == "-")
	{
		return 1;
	}
	return 0;
}

bool RPN::check_num(string the_word)
{
	bool num = 1;

	for(unsigned int i = 0; i < the_word.length(); i++)
	{
		if( !isdigit(the_word[i]) )
		{
			num = 0;
			break;
		}
	}

	return num;
	
}
