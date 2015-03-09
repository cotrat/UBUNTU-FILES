#ifndef HUMAN_H
#define HUMAN_H
#include <string>


class Human {
	public:
		Human();
		std::string getHand();
		void setHand(std::string hand);


		~Human();
		
	private:
		std::string hand;
};

#endif
