#include <string>
#include <iostream>
#include "Player.h"
#include "Avalanche.h"

using namespace std;

Avalanche::Avalanche() : Player("Avalanche") {}

Avalanche::~Avalanche() {}

string Avalanche::performMove()
{
	hand = "Rock";
	return hand;
}

