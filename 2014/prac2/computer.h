#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>


class Computer {
	public:
		Computer();
		int getHand();
		void setHand();


		~Computer();
		
	private:
		int handInt;
};

#endif
