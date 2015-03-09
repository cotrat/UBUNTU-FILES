#include "human.h"
#include "referee.h"
#include <string>


Human::Human(){
}

Human::~Human(){
}

std::string Human::getHand()
{
	return hand;
}

void Human::setHand(std::string value)
{
	hand = value;
}
