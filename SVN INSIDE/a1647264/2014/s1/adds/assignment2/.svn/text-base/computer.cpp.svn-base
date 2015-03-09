#include "computer.h"
#include "referee.h"
#include <string>
#include <iostream> //remove this
#include <cstdlib>
using namespace std;


Computer::Computer(){
	srand(time(NULL));
}

Computer::~Computer(){
}

int Computer::getHand()
{
	return handInt;
}

void Computer::addAnswer(string ans)
{
	userAnswers.push_back(ans);
}

void Computer::setHand()
{
	if(userAnswers.size() > 0)
	{
		if(userAnswers.back() == "rock")
		{
			handInt = 2;
		}
		else if(userAnswers.back() == "paper")
		{
			handInt = 0;
		}
		else if(userAnswers.back() == "scissors")
		{
			handInt = 1;
		}
		
	}
	else
	{
	handInt = rand() % 2; // Randomising 0,1,2
	}
}
