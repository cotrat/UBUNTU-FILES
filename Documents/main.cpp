#include "Stratego.h"
#include<string>
#include<iostream>

using namespace std;

void checktest(ConflictResolution result, ConflictResolution expected)
{
	if(result==expected)
	{
	cout << "it worked " << endl;
	}
	else{
	cout << "it didnt work " <<endl;
	}
}

string toString(ConflictResolution resolution)
{
switch (resolution)
{
	case ATTACKER_WINS:
		cout << " The attacking force has won the conflict! "<< endl;
		return("Attacker wins");
	case DEFENDER_WINS:
		cout << " The defending force has won the conflict! "<< endl;
		return("Defender Wins");
	case ATTACKER_AND_DEFENDER_LOSE:
		cout << " The conflict has resulted in a draw! "<< endl;
		return("It's a draw");
	case ATTACKER_WINS_GAME:
		cout << " The attacking force has captured the flag and won the game! "<< endl;
		return("Attacker wins game with flag capture");
	case INVALID_CONFLICT:
		cout << "That is an invalid move, what were you trying to do? " << endl;
		return("thats an invalid conflict");
}



}

int main(int argc, const char *argv[]) {
    
	string print,print1,print2,print3,print4,print5,print6,print7,print8,print9,print10,print11,print12;
    ConflictResolution expected = ATTACKER_WINS;
	ConflictResolution winner = resolveStrategoConflict('X','9');
	print = toString(winner);
	checkTest(winner,expected);

	ConflictResolution expected2 = DEFENDER_WINS;
	ConflictResolution winner2 = resolveStrategoConflict('8','9');
	print2= toString(winner2);
	checkTest(winner2,expected2);

	ConflictResolution expected3 = ATTACKER_WINS;
	ConflictResolution winner3 = resolveStrategoConflict('1','X');
	print3 = toString(winner3);
	checkTest(winner3,expected3);

	ConflictResolution expected4 = ATTACKER_WINS;
	ConflictResolution winner4 = resolveStrategoConflict('3','B');
	print4 = toString(winner4);
	checkTest(winner4,expected4);

	ConflictResolution expected5 = ATTACKER_WINS_GAME;
	ConflictResolution winner5 = resolveStrategoConflict('4','F');
	print5 = toString(winner5);
	checkTest(winner5,expected5);

	ConflictResolution expected6 = ATTACKER_AND_DEFENDER_LOSE;
	ConflictResolution winner6 = resolveStrategoConflict('5','5');
	print6 = toString(winner6);
	checkTest(winner6,expected6);

	ConflictResolution expected7 = INVALID_CONFLICT;
	ConflictResolution winner7 = resolveStrategoConflict('B','X');
	print7 = toString(winner7);
	checkTest(winner7,expected7);

	ConflictResolution expected8 = INVALID_CONFLICT;
	ConflictResolution winner8 = resolveStrategoConflict('F','X');
	print8 = toString(winner8);
	checkTest(winner8,expected8);

	ConflictResolution expected9 = DEFENDER_WINS;
	ConflictResolution winner9 = resolveStrategoConflict('8','B');
	print9 = toString(winner9);
	checkTest(winner9,expected9);

	ConflictResolution expected10 = INVALID_CONFLICT;
	ConflictResolution winner10 = resolveStrategoConflict('R','B');
	print10 = toString(winner10);
	checkTest(winner10,expected10);

	ConflictResolution expected11 = INVALID_CONFLICT;
	ConflictResolution winner11 = resolveStrategoConflict('R','P');
	print11 = toString(winner11);
	checkTest(winner11,expected11);

	ConflictResolution expected12 = INVALID_CONFLICT;
	ConflictResolution winner12 = resolveStrategoConflict('B','P');
	print12 = toString(winner12);
	checkTest(winner12,expected12);

    printTestingResults();

    return 0;
}



