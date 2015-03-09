#ifndef RPN_H
#define RPN_H

#include "myStack.h"
#include <vector>
#include <string>
class RPN
{
public:
	RPN(std::vector<std::string> input_values);
	RPN();
	~RPN();
	int execute();
	bool check_num(std::string);
	bool check_operator(std::string);
	

private:
	myStack* the_stack;
	std::vector<std::string> values;
	
};

#endif
