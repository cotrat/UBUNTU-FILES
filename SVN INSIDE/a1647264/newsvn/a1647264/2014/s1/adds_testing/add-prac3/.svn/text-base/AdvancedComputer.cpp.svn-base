#include "AdvancedComputer.h"
#include "Player.h"
#include <string>
#include <iostream> //remove this
#include <cstdlib>
using namespace std;


AdvancedComputer::AdvancedComputer() : Player("AdvancedComputer"){
	srand(time(NULL));
}

AdvancedComputer::~AdvancedComputer(){
}


void AdvancedComputer::addAnswer(string ans)
{
	userAnswers.push_back(ans);
}

string AdvancedComputer::performMove()
{
	if(userAnswers.size() > 0)
	{
		if(userAnswers.back() == "Rock")
		{
			handInt = 2;
		}
		else if(userAnswers.back() == "Paper")
		{
			handInt = 0;
		}
		else if(userAnswers.back() == "Scissors")
		{
			handInt = 1;
		}
		
	}
	else
	{
	handInt = rand() % 2; // Randomising 0,1,2
	}
}
