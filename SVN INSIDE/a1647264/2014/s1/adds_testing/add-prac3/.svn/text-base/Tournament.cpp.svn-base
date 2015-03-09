#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Tournament.h"
#include "Referee.h"

using namespace std;

Tournament::Tournament() {
}

Tournament::~Tournament() {
}

string Tournament::compete() {


	int i =0; // ITERATOR VARIABLE
	int j; // ITERATOR VARIABLE
	int k;
	int z=0;
	int itr;
	string fight_winner; // STORES THE RUNNING WINNER
	int p1wins = 0; // STORES P1 WINS
	int p2wins = 0; // STORES P2 WINS
	Referee newRef; // CREATING A REF FOR THE TOURNAMENT



	for(k=0; k<4; k++) // ROUND 1 OF THE TOURNAMENT 
	{
		
		cout << " THE PLAYERS ARE " << Round1.at(i)->getName() << " AND " << Round1.at(i+1)->getName() << endl;
		for(j = 0; j < 5; j++)
		{
			fight_winner = newRef.Fight(Round1.at(i), Round1.at(i+1)); // Finding the fight winners and storing in the string
			cout << "THE FIGHT WINNER WAS " << fight_winner << endl;
			if(fight_winner == "p1")
			{
				p1wins++; // Iterating p1 wins
				cout << "P1 WON THAT ROUND AND HAS NOW WON " << p1wins << endl;
			}
			else if(fight_winner == "p2")
			{
				p2wins++; // Iterating p2wins
				cout << "P2 WON THAT ROUND AND HAS NOW WON " << p2wins << endl;
			}
		}

		// Following block of code is pushing back the winners into the 'Round2 Vector'
		if(p1wins > p2wins)
		{
			Round2.push_back(Round1.at(i));
			cout << Round1.at(i)->getName() << "Was Pusghed Back ";
		}
		else if(p2wins > p1wins)
		{
			Round2.push_back(Round1.at(i+1));
			cout << Round1.at(i+1)->getName() << "Was Pusghed Back ";
		}
		else if(p2wins == p1wins)
		{
			Round2.push_back(Round1.at(i));
			cout << Round1.at(i)->getName() << "Was Pusghed Back ";
		}
		p1wins = 0;
		p2wins = 0;
		i+=2;
		cout << endl << endl << endl;
	}
	i = 0;
	//RESETTING PLAYERS

	for(k=0; k<Round2.size(); k++)
	{
		Round2.at(k)->setCtr(0);
	}


	//
	cout << "ROUND 2";
	for(k=0;k<2;k++)
	{
		cout << " THE PLAYERS ARE " << Round2.at(i)->getName() << " AND " << Round2.at(i+1)->getName() << endl;

	for(j = 0; j < 5; j++)
		{
			fight_winner = newRef.Fight(Round2.at(i), Round2.at(i+1)); // Finding the fight winners and storing in the string
			cout << "THE FIGHT WINNER WAS " << fight_winner << endl;
			if(fight_winner == "p1")
			{
				p1wins++; // Iterating p1 wins
				cout << "P1 WON THAT ROUND AND HAS NOW WON " << p1wins << endl;
			}
			else if(fight_winner == "p2")
			{
				p2wins++; // Iterating p2wins
				cout << "P2 WON THAT ROUND AND HAS NOW WON " << p2wins << endl;
			}
		}
		// Following block of code is pushing back the winners into the 'Round2 Vector'
		if(p1wins > p2wins)
		{
			Round3.push_back(Round2.at(i));
			cout << Round2.at(i)->getName() << "Was Pusghed Back ";
		}
		else if(p2wins > p1wins)
		{
			Round3.push_back(Round2.at(i+1));
			cout << Round2.at(i+1)->getName() << "Was Pusghed Back ";
		}
		else if(p2wins == p1wins)
		{
			Round3.push_back(Round2.at(i));
			cout << Round2.at(i)->getName() << "Was Pusghed Back ";
		}
		i+=2;
		p1wins = 0;
		p2wins = 0;
		cout << endl << endl << endl;
	}

	//RESETTING PLAYERS
	for(k=0; k<Round2.size(); k++)
	{
		Round2.at(k)->setCtr(0);
	}
	//

	//ROUND 3
	for(j = 0; j < 5; j++)
		{
			fight_winner = newRef.Fight(Round3.at(0), Round3.at(1)); // Finding the fight winners and storing in the string
			cout << "THE FIGHT WINNER WAS " << fight_winner << endl;
			if(fight_winner == "p1")
			{
				p1wins++; // Iterating p1 wins
				cout << "P1 WON THAT ROUND AND HAS NOW WON " << p1wins << endl;
			}
			else if(fight_winner == "p2")
			{
				p2wins++; // Iterating p2wins
				cout << "P2 WON THAT ROUND AND HAS NOW WON " << p2wins << endl;
			}
		}

		// Checking who won!
		if(p1wins > p2wins)
		{
			
			cout << Round3.at(0)->getName() << "WINNER ";
		}
		else if(p2wins > p1wins)
		{
			cout << Round3.at(1)->getName() << "WINNER ";
		}
		else if(p2wins == p1wins)
		{
			
			cout << Round3.at(0)->getName() << "WINNER ";
		}
		i+=2;
		p1wins = 0;
		p2wins = 0;
		cout << endl << endl << endl;
	
}

void Tournament::addPlayers(Player* newPlayer)
{
	Round1.push_back(newPlayer);
}
