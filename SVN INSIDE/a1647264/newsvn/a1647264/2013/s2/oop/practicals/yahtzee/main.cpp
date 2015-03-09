#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <sstream>
#include "DiceRoll.h"
#include "Die.h"

using namespace std;

void test_cases();
void filestream();

int main(int argc, const char *argv[]) {
    srand(time(NULL));
    	int x;
	for(x=0; x<argc; x++)
	{
		string argstr = string(argv[x]);
		if(argstr == "-test")
		{
			test_cases();
		}
		if(argstr == "-fs")
		{
			filestream();
		}
	}


    return 0;
}

void filestream()
{
	ifstream myFileStream("values.txt");
	vector<Die> testDice;
	string numStr;
	int num;
	
	while(myFileStream >> numStr)
	{
		istringstream(numStr) >> num;
		Die die(num);
		testDice.push_back(die);
	}

	DiceRoll myDice = DiceRoll(testDice);
	myDice.getFaces();
	bool fh = myDice.isFH();
	bool trip = myDice.isTriple();
	bool quad = myDice.isQuad();
	bool yahtzee = myDice.isFive();

	if(fh == 1)
	{
		cout << "It was a full house"<< endl;
	}
	if(trip == 1)
	{
		cout << "It was a 3 of a kind "<< endl;
	}
	if(quad == 1)
	{
		cout << "It was a 4 of a kind"<< endl;
	}
	if(yahtzee == 1)
	{
		cout << "It was a yahtzee"<< endl;
	}
	
}




void test_cases()
{
	// Testing a full house
	vector<Die> testDice;
	Die die1(6);
	Die die2(6);
	Die die3(6);
	Die die4(2);
	Die die5(2);
	testDice.push_back(die1);
	testDice.push_back(die2);
	testDice.push_back(die3);
	testDice.push_back(die4);
	testDice.push_back(die5);
	DiceRoll myDice = DiceRoll(testDice);
	
	myDice.getFaces();
	bool fh = myDice.isFH();
	bool trip = myDice.isTriple();
	bool quad = myDice.isQuad();
	bool yahtzee = myDice.isFive();

	if(fh == 1)
	{
		cout << "It was a full house"<< endl;
	}
	if(trip == 1)
	{
		cout << "It was a 3 of a kind "<< endl;
	}
	if(quad == 1)
	{
		cout << "It was a 4 of a kind"<< endl;
	}
	if(yahtzee == 1)
	{
		cout << "It was a yahtzee"<< endl;
	}
	
	cout << endl;
	cout << endl;
	cout << endl;

	// Testing a triple
	vector<Die> testDice2;
	Die die21(6);
	Die die22(6);
	Die die23(6);
	Die die24(1);
	Die die25(2);
	testDice2.push_back(die21);
	testDice2.push_back(die22);
	testDice2.push_back(die23);
	testDice2.push_back(die24);
	testDice2.push_back(die25);
	DiceRoll myDice2 = DiceRoll(testDice2);
	
	myDice2.getFaces();
	bool fh2 = myDice2.isFH();
	bool trip2 = myDice2.isTriple();
	bool quad2 = myDice2.isQuad();
	bool yahtzee2 = myDice2.isFive();

	if(fh2 == 1)
	{
		cout << "It was a full house"<< endl;
	}
	if(trip2 == 1)
	{
		cout << "It was a 3 of a kind "<< endl;
	}
	if(quad2 == 1)
	{
		cout << "It was a 4 of a kind"<< endl;
	}
	if(yahtzee2 == 1)
	{
		cout << "It was a yahtzee"<< endl;
	}
	
	cout << endl;
	cout << endl;
	cout << endl;

	// Testing a quad
	vector<Die> testDice3;
	Die die31(6);
	Die die32(6);
	Die die33(6);
	Die die34(6);
	Die die35(2);
	testDice3.push_back(die31);
	testDice3.push_back(die32);
	testDice3.push_back(die33);
	testDice3.push_back(die34);
	testDice3.push_back(die35);
	
	DiceRoll myDice3 = DiceRoll(testDice3);
	
	myDice3.getFaces();
	bool fh3 = myDice3.isFH();
	bool trip3 = myDice3.isTriple();
	bool quad3 = myDice3.isQuad();
	bool yahtzee3 = myDice3.isFive();
	
	if(fh3 == 1)
	{
		cout << "It was a full house"<< endl;
	}
	if(trip3 == 1)
	{
		cout << "It was a 3 of a kind "<< endl;
	}
	if(quad3 == 1)
	{
		cout << "It was a 4 of a kind"<< endl;
	}
	if(yahtzee3 == 1)
	{
		cout << "It was a yahtzee"<< endl;
	}	

	cout << endl;
	cout << endl;
	cout << endl;

	// Testing the reroll
	vector<Die> testDice4;
	Die die41(6);
	Die die42(6);
	Die die43(6);
	Die die44(6);
	Die die45(2);
	testDice4.push_back(die41);
	testDice4.push_back(die42);
	testDice4.push_back(die43);
	testDice4.push_back(die44);
	testDice4.push_back(die45);
	DiceRoll myDice4 = DiceRoll(testDice4);
	
	myDice4.getFaces();
	myDice4.reRoll();
	cout << "It has been rerolled to ";
	myDice4.getFaces();

	cout << endl;
	cout << endl;
	cout << endl;

	// Testing the count & sum
	vector<Die> testDice5;
	Die die51(1);
	Die die52(2);
	Die die53(2);
	Die die54(3);
	Die die55(2);
	testDice5.push_back(die51);
	testDice5.push_back(die52);
	testDice5.push_back(die53);
	testDice5.push_back(die54);
	testDice5.push_back(die55);
	DiceRoll myDice5 = DiceRoll(testDice5);
	
	myDice5.getFaces();
	unsigned int sum = myDice5.theSum();
	unsigned int how1 = myDice5.howMany(1);
	unsigned int how2 = myDice5.howMany(2);
	unsigned int how3 = myDice5.howMany(3);
	
	cout << "There was " << how1 << " occurences of the number 1" << endl;
	cout << "There was " << how2 << " occurences of the number 2" << endl;
	cout << "There was " << how3 << " occurences of the number 3" << endl;
	cout << "The sum was " << sum << endl;


	cout << endl;
	cout << endl;
	cout << endl;

	// Testing a yahtzee
	vector<Die> testDice6;
	Die die61(6);
	Die die62(6);
	Die die63(6);
	Die die64(6);
	Die die65(6);
	testDice6.push_back(die61);
	testDice6.push_back(die62);
	testDice6.push_back(die63);
	testDice6.push_back(die64);
	testDice6.push_back(die65);
	
	DiceRoll myDice6 = DiceRoll(testDice6);
	
	myDice6.getFaces();
	bool fh6 = myDice6.isFH();
	bool trip6 = myDice6.isTriple();
	bool quad6 = myDice6.isQuad();
	bool yahtzee6 = myDice6.isFive();
	
	if(fh6 == 1)
	{
		cout << "It was a full house" << endl;
	}
	if(trip6 == 1)
	{
		cout << "It was a 3 of a kind "<< endl;
	}
	if(quad6 == 1)
	{
		cout << "It was a 4 of a kind"<< endl;
	}
	if(yahtzee6 == 1)
	{
		cout << "It was a yahtzee"<< endl;
	}	

	
	
}

