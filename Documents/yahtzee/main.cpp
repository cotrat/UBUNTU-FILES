#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "DiceRoll.h"
#include "Die.h"

using namespace std;

int main(int argc, const char *argv[]) {
    srand(time(NULL));
    
    Die die(7);
    cout << "Initial Dice Face: " << die.getFace() << endl;

	// MY TESTING
	vector<Die> testDice;
	Die die1(7);
	Die die2(7);
	Die die3(7);
	Die die4(7);
	testDice.push_back(die1);
	testDice.push_back(die2);
	testDice.push_back(die3);
	testDice.push_back(die4);

	
	DiceRoll myDice;
	myDice.addDice(testDice);
	vector<int> mySum = myDice.getFaces();
	



	// END MY TESTING

    const unsigned int NUMBER_OF_ROLES = 5;
    for(unsigned int currRoll = 0; currRoll < NUMBER_OF_ROLES; currRoll++) {
        die.roll();
        cout << "Roll Number " << (currRoll + 1) << ": " << die.getFace() << endl;
    }

    return 0;
}

