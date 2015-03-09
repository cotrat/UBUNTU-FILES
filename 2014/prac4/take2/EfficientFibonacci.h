#ifndef EFFICIENTFIBONNACI_H
#define EFFICIENTFIBONNACI_H
#include <string>
#include <vector>


class EfficientFibonacci {
	public:
		EfficientFibonacci();
		int ApplyEfficientFibonacci(int);
		int ApplySlowFibonacci(int);
		bool checkWord(std::string);
		~EfficientFibonacci();
		
	private:
		
		std::vector<int> m_calculated;
		
};

#endif
