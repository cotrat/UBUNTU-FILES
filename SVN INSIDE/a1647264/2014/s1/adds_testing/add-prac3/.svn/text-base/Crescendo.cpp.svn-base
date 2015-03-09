#include <string>
#include <iostream>
#include "Player.h"
#include "Crescendo.h"

using namespace std;

Crescendo::Crescendo() : Player("Crescendo") {
	ctr = 0;
}

Crescendo::~Crescendo() {}

void Crescendo::setCtr(int newCtr)
{
	ctr = newCtr;
}

string Crescendo::performMove()
{
	if (ctr == 0)
	{
		return "Paper";
	}
	if (ctr == 1)
	{
		return "Scissors";
	}
	if (ctr == 2)
	{
		return "Rock";
	}
}

