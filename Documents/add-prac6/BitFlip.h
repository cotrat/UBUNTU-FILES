#ifndef BITFLIP_H
#define BITFLIP_H
#include "Individual.h"
#include "binaryNode.h"
#include "BitFlip.h"
#include <string>


class BitFlip : public Individual {

public:
	BitFlip(std::string);
	void execute(int k);
private:
	
	
};

#endif
