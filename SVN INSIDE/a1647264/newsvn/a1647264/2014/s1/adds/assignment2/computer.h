#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <vector>


class Computer {
	public:
		Computer();
		int getHand();
		void setHand();
		void addAnswer(std::string ans);

		~Computer();
		
	private:
		int handInt;
		std::vector<std::string> userAnswers;
		
};

#endif
