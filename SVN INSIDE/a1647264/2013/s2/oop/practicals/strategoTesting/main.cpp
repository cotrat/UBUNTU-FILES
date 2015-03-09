#include "Stratego.h"
#include<iostream>
#include<string>
using namespace std;

void checkTest(ConflictResolution result, ConflictResolution expected)
{
  if(result==expected)
    {
      cout << "The test has passed!" << endl;
    }
  else{
    cout << "The test has failed, the expected result was "<< expected << "But the given result was " << result <<endl;
  }

}

string toString(ConflictResolution resolution)
{
  switch (resolution)
    {
    case ATTACKER_WINS:
      //cout << " The attacking force has won the conflict! "<< endl;
      return("ATTACKER_WINS ");
    case DEFENDER_WINS:
      //cout << " The defending force has won the conflict! "<< endl;
      return("DEFENDER_WINS ");
    case ATTACKER_AND_DEFENDER_LOSE:
      //cout << " The conflict has resulted in a draw! "<< endl;
      return("DRAW ");
    case ATTACKER_WINS_GAME:
      //cout << " The attacking force has captured the flag and won the game! "<< endl;
      return("ATTACKER_WINS_GAME ");
    case INVALID_CONFLICT:
      //cout << "That is an invalid move, what were you trying to do? " << endl;
      return("INVALID ");
    }



}

int main(int argc, const char *argv[]) {
    
	string print,print1,print2,print3,print4,print5,print6,print7,print8,print9,print10,print11,print12;
    ConflictResolution expected = ATTACKER_WINS;
	ConflictResolution winner = resolveStrategoConflict('X','9');
	print = toString(winner);
	checkTest(winner,expected);
  string print,print2,print3,print4,print5,print6,print7,print8,print9,print10,print11,print12;

  ConflictResolution expected = ATTACKER_WINS;
  ConflictResolution winner = resolveStrategoConflict('X','9'); // checking normal higher attacker value win
  print = toString(winner);
  cout << print;
  checkTest(winner,expected);

  ConflictResolution expected2 = DEFENDER_WINS;
  ConflictResolution winner2 = resolveStrategoConflict('8','9'); // checking higher defender value victory
  print2= toString(winner2);
  cout << print2;
  checkTest(winner2,expected2);

  ConflictResolution expected3 = ATTACKER_WINS;
  ConflictResolution winner3 = resolveStrategoConflict('1','X'); // checking that spy beats marshal
  print3 = toString(winner3);
  cout << print3;
  checkTest(winner3,expected3);

  ConflictResolution expected4 = ATTACKER_WINS;
  ConflictResolution winner4 = resolveStrategoConflict('3','B'); // checking that miner beats bomb
  print4 = toString(winner4);
  cout << print4;
  checkTest(winner4,expected4);

  ConflictResolution expected5 = ATTACKER_WINS_GAME;
  ConflictResolution winner5 = resolveStrategoConflict('4','F'); // checking that beating flag wins the game
  print5 = toString(winner5);
  cout << print5;
  checkTest(winner5,expected5);

  ConflictResolution expected6 = ATTACKER_AND_DEFENDER_LOSE;
  ConflictResolution winner6 = resolveStrategoConflict('5','5'); // checking that equal value results in a draw
  print6 = toString(winner6);
  cout << print6;
  checkTest(winner6,expected6);

  ConflictResolution expected7 = INVALID_CONFLICT;
  ConflictResolution winner7 = resolveStrategoConflict('B','X'); // checking that bomb cannot attack
  print7 = toString(winner7);
  cout << print7;
  checkTest(winner7,expected7);

  ConflictResolution expected8 = INVALID_CONFLICT;
  ConflictResolution winner8 = resolveStrategoConflict('F','X'); // checking that flag cannot attack
  print8 = toString(winner8);
  cout << print8;
  checkTest(winner8,expected8);

  ConflictResolution expected9 = DEFENDER_WINS;
  ConflictResolution winner9 = resolveStrategoConflict('8','B'); // checking that bomb beats non-miners
  print9 = toString(winner9);
  cout << print9;
  checkTest(winner9,expected9);

  ConflictResolution expected10 = INVALID_CONFLICT;
  ConflictResolution winner10 = resolveStrategoConflict('R','B'); // checking that the attacker cannot be an invalid char
  print10 = toString(winner10);
  cout << print10;
  checkTest(winner10,expected10);

 // ConflictResolution expected11 = INVALID_CONFLICT;
  //ConflictResolution winner11 = resolveStrategoConflict('R','P');
  //print11 = toString(winner11);
 // cout << print11 << endl;
  //checkTest(winner11,expected11);

  ConflictResolution expected12 = INVALID_CONFLICT;
  ConflictResolution winner12 = resolveStrategoConflict('B','P'); // checking that defender cannot be an invalid char
  print12 = toString(winner12);
  cout << print12;
  checkTest(winner12,expected12);

    printTestingResults();

    return 0;
}



