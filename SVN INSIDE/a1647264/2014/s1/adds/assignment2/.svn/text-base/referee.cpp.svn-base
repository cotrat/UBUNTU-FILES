#include "human.h"
#include "referee.h"
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

Referee::Referee(){
	
}

Referee::~Referee(){
}

string Referee::cleanUp(string toClean)
{
	int i;
	char newStr[250];
	strcpy(newStr,toClean.c_str());
	for(i = 0;i < toClean.size(); i ++) 
	{
		if((newStr[i] > 64) and (newStr[i] < 91))
		{
			newStr[i] = newStr[i] + 32; // when the char is between 65 and 90 inclusive it needs to be shifted into lower case (this is using the ASCII table)
		}
	
	}
	
	toClean = newStr;
	if(toClean == "scissor")
	{
		toClean = "scissors";
	}

	cout << "The Auto Clean-up changed your entry to " << toClean << endl;
	return toClean;
}
bool Referee::checkHand(string hand)
{
	
	if ((hand=="scissors") or (hand=="rock") or (hand=="paper"))
	{	
		return 1;
	}
}
	
int Referee::checkWinner(std::string playersHand, int computersHand)
{				// With regards to computer 0 = Paper, 1 = Scissors, 2 = Rock 
	switch(computersHand) // 1 = Winner 2 = Loser 0 = Draw
	{
		case 0:
			if(playersHand=="scissors")
				return 1;
			if(playersHand=="paper")
				return 0;
			if(playersHand=="rock")
				return 2;
		case 1:
			if(playersHand=="rock")
				return 1;
			if(playersHand=="scissors")
				return 0;
			if(playersHand=="paper")
				return 2;
		case 2:
			if(playersHand=="paper")
				return 1;
			if(playersHand=="rock")
				return 0;
			if(playersHand=="scissors")
				return 2;
	}
}	

