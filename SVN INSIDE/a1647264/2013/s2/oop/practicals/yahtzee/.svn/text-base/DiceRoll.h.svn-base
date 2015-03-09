#ifndef DICEROLL_H
#define DICEROLL_H
#include "Die.h"
#include<vector>
#include<string>
class DiceRoll {
	public:
		DiceRoll();
		DiceRoll(std::vector<Die> faces);
		~DiceRoll();
		
		void getFaces() const;
		
		unsigned int howMany(unsigned int value) const;
		void reRoll();
		
		unsigned int theSum() const;
		bool isTriple() const;
		bool isQuad() const;
		bool isFH() const;
		bool isFive() const;
		std::string score();
	private:
		std::vector<Die> m_Dice;
};

#endif

