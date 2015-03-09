// rand: cstdlib; cin cout: iostream; string operators: string; list: vector
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;




int countLetter(string word, char guess)
{
	int it;
	int count=0;
	

	
	for (it = 0; it < word.size(); it++)
	{
		
		
		if (word[it]==guess)
		{
			count++;
			
		}
	
	}
	cout << "The letter has appeared " << count << " Times " <<endl;
	return(0);
}

int main()
{
  string word,word2,word3;
  char guess,guess2,guess3;
  word = " hello";
  word2 = "goodbye";
  word3 = "different";
  guess = 'l';
  guess2 = 'o';
  guess3 = 'f';
  // cout << "Enter your word!";
  // cin >> word;
  // cout << "Enter your letter!";
  // cin >> guess;
  countLetter(word,guess);
  countLetter(word2,guess2);
  countLetter(word3,guess3);
  
  return(0);
}
