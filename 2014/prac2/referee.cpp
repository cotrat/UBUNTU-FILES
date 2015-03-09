#include "human.h"
#include "referee.h"
#include <vector>
#include <string>
using namespace std;

Referee::Referee(){
	
}

Referee::~Referee(){
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

