#include "AdvancedComputer.h"
#include "Player.h"
#include <string>
#include <iostream> //remove this
#include <cstdlib>
using namespace std;


AdvancedComputer::AdvancedComputer() : Player("AdvancedComputer"){
	
}

AdvancedComputer::~AdvancedComputer(){
}


void AdvancedComputer::addAnswer(string ans)
{
	userAnswers.push_back(ans);
}

string AdvancedComputer::performMove()
{
	if(userAnswers.size() > 0)	// Checking the back of the vector (which contains its opponents answers) and then chosing the latest answer
	{
		if(userAnswers.back() == "Rock")
		{
			return "Rock";
		}
		else if(userAnswers.back() == "Paper")
		{
			return "Paper";
		}
		else if(userAnswers.back() == "Scissors")
		{
			return "Scissors";
		}
		
	}
	else
	{
		int handInt = rand() % 2; // Randomising the first input because the AdvancedComputer cannot play a previous move if there is none
		if (handInt == 0)
		{
			return "Rock";
		}
		else if(handInt == 1)
		{
			return "Paper";
		}
		else if(handInt == 2)
		{
			return "Scissors";
		}
	}

	return 0; // Remove Warning Flag
}
