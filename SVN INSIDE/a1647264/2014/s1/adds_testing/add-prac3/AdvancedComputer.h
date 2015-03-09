#ifndef AdvancedComputer_H
#define AdvancedComputer_H
#include <string>
#include "Player.h"
#include <vector>


class AdvancedComputer : public Player {
	public:
		AdvancedComputer();
		std::string performMove();
		void addAnswer(std::string ans);

		~AdvancedComputer();
		
	private:
		int handInt;
		std::vector<std::string> userAnswers;
		
};

#endif
