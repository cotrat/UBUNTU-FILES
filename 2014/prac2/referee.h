#ifndef REFEREE_H
#define REFEREE_H
#include "human.h"
#include <string>


class Referee {
	public:
		Referee();
		bool checkHand(std::string hand);	
		
		int checkWinner(std::string playersHand, int computersHand);


		~Referee();
		
	private:
		
		
};

#endif
