#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "binaryNode.h"
#include <string>


class Individual
{
public:
	~Individual();
	Individual(std::string);
	Individual(int length);
	Individual(binaryNode *the_head);
	virtual void execute(int k);
	void setFirstBit(binaryNode* newHead);
	int getMaxOnes();
	int getLength();	
	std::string getString();
	binaryNode *head;
private:
	// First Node in the linked-list
	
};

#endif
