#include "human.h"
#include "referee.h"
#include "computer.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;


int main()
{
	srand(time(NULL)); // Reseed Random
	Human myHuman; //This is you, the player
	Referee myRef; // What he says goes!
	Computer myComputer; // He is going to beat you
	
	bool valid = 0; // Bool to check if the user has a valid entry
	char cont = 'y'; // does the user want to keep playing?

	string entry; // The users choice of weapon
	
	
	while(cont == 'y')
	{
		cout << "Please type one of: rock, paper, scissors" << endl; // Accepting the users entry
		cin >> entry;
		myComputer.setHand(); // Setting the AI's weapon
		while(!valid)
		{
			entry = myRef.cleanUp(entry);
			valid = myRef.checkHand(entry); // checking if it is valid
			if(!valid)
			{
				cout << "Not a valid entry, how about you try typing it in again?" << endl;
				cin >> entry;
			}
		}
		
		
		switch(myComputer.getHand()) // This switch statement is simply tellingthe user what the AI picked
		{
			case 0:
				cout << "The AI Chose Paper! " << endl;
				break;
			case 1:
				cout << "The AI Chose Scissors! " << endl;
				break;
			case 2:
				cout << "The AI Chose Rock!" << endl;
				break;
		}

		switch(myRef.checkWinner(entry,myComputer.getHand())) // This switch statement is to tell the user who won
		{
			case 0:
				cout << "Its a draw " << endl;
				break;
			case 1:
				cout << "YOU WON " << endl;
				break;
			case 2:
				cout << "You lost" << endl;
				break;
		}
		
		myComputer.addAnswer(entry);
		cout << "Do you want to keep playing y/n "; // Checking if the user wants to continue playing
		cin >> cont;
		valid = 0; // Resetting the validation
	}
	
	
	
	
}
