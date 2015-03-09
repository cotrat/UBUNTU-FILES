#include "Die.h"
#include "DiceRoll.h"
#include<vector>
#include<iostream>
using namespace std;

//Argument-less Constructor

DiceRoll::DiceRoll(){
	int x;
	for(x = 0; x < 5; x++)
	{
		Die myDie;
		myDie.roll();
		m_Dice.push_back(myDie);
	}
}

DiceRoll::DiceRoll(vector<Die> faces):m_Dice(faces){
}

DiceRoll::~DiceRoll(){
}


void DiceRoll::getFaces() const{
	
	
	for(int x = 0; x < m_Dice.size(); x++)
	{
		cout << m_Dice[x].getFace() << " ";
	}
	cout << endl;
}

unsigned int DiceRoll::howMany(unsigned int value) const
{
	unsigned int count = 0;
	for(int x = 0; x < m_Dice.size(); x++)
	{
		if(m_Dice[x].getFace() == value)
		{
			count++;
		}
	}
	return count;
}

void DiceRoll::reRoll(){
	for(int x = 0; x < m_Dice.size(); x++)
	{
		m_Dice[x].roll();
	}
}



unsigned int DiceRoll::theSum() const
{
	unsigned int count = 0;
	for(int x = 0; x < m_Dice.size(); x++)
	{
		count = count + m_Dice[x].getFace();
	}
	return count;
}

bool DiceRoll::isTriple() const
{
	int x;
	unsigned int check;
	unsigned int check2;
	int check_arr[m_Dice.size()];
	unsigned int count = 0;
	
	for(x = 0; x < m_Dice.size(); x++) // Iterating through each dice 
	{
		check = m_Dice[x].getFace();
		
		for(int y = 0; y < m_Dice.size(); y++) // Checking it against every other dice
		{
			check2 = m_Dice[y].getFace();
			
			if(check2==check) // if they match increase count
			{
				count++;	
			}
		
		}
		
		check_arr[x] = count; // Store count value in an array
		count = 0;		// Reset count back to 0
	}
	
	for(x = 0; x < m_Dice.size(); x++)	// Check if any value in count is two or higher
	{
		if(check_arr[x] >= 3)
		{
			return 1;
		}
	}
	return 0;
}

bool DiceRoll::isQuad() const
{
	
	unsigned int check;
	unsigned int check2;
	int check_arr[m_Dice.size()];
	unsigned int count = 0;
	int x;
	
	for (x = 0; x < m_Dice.size(); x++) // Iterating through each dice 
	{
		check = m_Dice[x].getFace();
		
		for(int y = 0; y < m_Dice.size(); y++) // Checking it against every other dice
		{
			check2 = m_Dice[y].getFace();
			
			if(check2==check) // if they match increase count
			{
				count++;	
			}
		
		}
		
		check_arr[x] = count; // Store count value in an array
		count = 0;		// Reset count back to 0
	}
	
	for(x = 0; x < m_Dice.size(); x++)	// Check if any value in count is two or higher
	{
		if(check_arr[x] >= 4)
		{
			return 1;
		}
	}
	return 0;
}

bool DiceRoll::isFH() const
{
	// CHECKING IF THERE IS A TRIPLE FIRST
	unsigned int check;
	unsigned int check2;
	int check_arr[m_Dice.size()];
	unsigned int count = 0;
	bool trip;
	int x;
	int position;
	
	for(x = 0; x < m_Dice.size(); x++) // Iterating through each dice 
	{
		check = m_Dice[x].getFace();
		
		for(int y = 0; y < m_Dice.size(); y++) // Checking it against every other dice
		{
			check2 = m_Dice[y].getFace();
			
			if(check2==check) // if they match increase count
			{
				count++;	
			}
		
		}
		
		check_arr[x] = count; // Store count value in an array
		count = 0;		// Reset count back to 0
	}
	
	


	for(x = 0; x < m_Dice.size(); x++)	// Check if any value in count is two or higher
	{
		if(check_arr[x] >= 3)
		{
			position = x;
			trip = 1;
			
			break;
		}
	}	
	// END OF TRIPLE CHECK

	if(trip==1)
	{
		// FIND THE TWO ELEMENTS THAT ARENT THE TRIPLE
		int nTripleArr[2];
		count = 0;
		
		for(x = 0; x < m_Dice.size(); x++) // Iterating through each dice 
		{
			if(m_Dice[x].getFace() != m_Dice[position].getFace())
			{
				nTripleArr[count] = m_Dice[x].getFace();
				count++;
			}
		}
		

		if(nTripleArr[0] == nTripleArr[1])
		{
			return 1;
		}
	}
	
	return 0;
}

bool DiceRoll::isFive() const
{
	int x;
	int check = m_Dice[0].getFace();
	for(x = 0; x < m_Dice.size(); x++) // Iterating through each dice 
	{
		if(check!=m_Dice[x].getFace())
		{
			return 0;
		}
	}
	return 1;
}
/*
string DiceRoll::score()
{
	bool triple,quad,fh,five;
	
	five = isFive();
	quad = isQuad();
	fh = isFH();
	triple = isTriple();
	
	if(fh)
	{
		return "The roll was a full house";
	}
	else if(five)
	{
		return "The roll wasa  5 of a kind";
	}
	else if(quad)
	{
		return "The roll was a 4 of a kind";
	}
	else if(triple)
	{
		return "The Roll was a 3 of a kind";
	}
	else
	{
		return "You didnt score any of the designated score amounts";
	}
	
	
	
}*/
