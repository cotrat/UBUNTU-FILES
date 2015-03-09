#include "computer.h"
#include "referee.h"
#include <string>
#include <cstdlib>


Computer::Computer(){
	srand(time(NULL));
}

Computer::~Computer(){
}

int Computer::getHand()
{
	return handInt;
}

void Computer::setHand()
{
	
	handInt = rand() % 2; // Randomising 0,1,2
}
