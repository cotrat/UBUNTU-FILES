#include "Die.h"
#include "DiceRoll.h"
#include<vector>
#include<iostream>
using namespace std;

//Argument-less Constructor

DiceRoll::DiceRoll(){
}

DiceRoll::DiceRoll(vector<Die> faces):m_Dice(faces){
}

DiceRoll::~DiceRoll(){
}


vector<int> DiceRoll::getFaces() const{
	
	vector<int> faces_inside;
	for(int x = 0; x < m_Dice.size(); x++)
	{
		faces_inside.push_back(m_Dice[x].getFace());
	}
	return faces_inside;
}

unsigned int DiceRoll::howMany(unsigned int value){
	unsigned int count;
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

void DiceRoll::addDice(vector<Die> diceVector){
	for(int x = 0; x < diceVector.size(); x++)
	{
		m_Dice.push_back(diceVector[x]);
	}
	
}


unsigned int DiceRoll::theSum(){
	unsigned int count = 0;
	for(int x = 0; x < m_Dice.size(); x++)
	{
		count = count + m_Dice[x].getFace();
	}
	return count;
}

/*
unsigned int DiceRoll::score(){
unsigned int count = 0;
	for(int x = 0; x < m_Dice.size(); x++)
	{
		unsigned int check = m_Dice[x].getFace
		for(int y = 0; y < m_Dice.size(); y++)
		{
			if(m_Dice[y].getFace==check)
			{
				count++;
			}
		}
	}


}

*/
