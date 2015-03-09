#include "human.h"
#include "referee.h"
#include "computer.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void clean(string * toClean)
{
	int i;
	
	char newStr[250];
	strcpy(newStr,toClean->c_str());
	for(i = 0;i < toClean->size(); i ++) 
	{
		if((newStr[i] > 64) and (newStr[i] < 91))
		{
			newStr[i] = newStr[i] + 32; // when the char is between 65 and 90 inclusive it needs to be shifted into lower case (this is using the ASCII table)
		}

	
	}	
	*toClean = newStr;
	

}
int main()
{
	srand(time(NULL)); // Reseed Random
	Human myHuman; //This is you, the player
	Referee myRef; // What he says goes!
	Computer myComputer; // He is going to beat you
	myComputer.setHand();
	bool valid = 0;
	string entry;
	cout << "Please type one of: rock, paper, scissors" << endl; // Accepting the users entry
	cin >> entry;
	cout << rand() % 100;
	while(!valid)
	{
		valid = myRef.checkHand(entry); // checking if it is valid
		if(!valid)
		{
			cout << "This was not a valid entry, i'll attempt to clean it up (change to lowercase)" << endl;
			clean(&entry);
			cout << entry << " - Here it is cleaned up" << endl;
			valid = myRef.checkHand(entry); // checking if it is valid
		}
		if(!valid)
		{
			cout << "Still not a valid entry, how about you try typing it in again?" << endl;
			cin >> entry;
		}
	}
	cout << entry;
	
	
	int compsHand = myComputer.getHand();
	cout << myComputer.getHand();
	int whoWon = myRef.checkWinner(entry, compsHand);
	cout << whoWon;
}
