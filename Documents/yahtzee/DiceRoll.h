#ifndef DICEROLL_H
#define DICEROLL_H
#include "Die.h"
#include<vector>

class DiceRoll {
	public:
		DiceRoll();
		DiceRoll(std::vector<Die> faces);
		~DiceRoll();
		
		std::vector<int> getFaces() const;
		void addDice(std::vector<Die> diceVector);
		unsigned int howMany(unsigned int value);
		void reRoll();
		
		unsigned int theSum();
		//unsigned int score();
	private:
		std::vector<Die> m_Dice;
};

#endif

