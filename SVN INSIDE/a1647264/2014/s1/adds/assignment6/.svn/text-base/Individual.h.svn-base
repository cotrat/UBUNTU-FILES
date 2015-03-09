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
	binaryNode* getFirstBit();
	void setFirstBit(binaryNode* newHead);
	int getMaxOnes();
	int getLength();	
	std::string getString();
protected:
	binaryNode *head;
private:
	
	
};

#endif
