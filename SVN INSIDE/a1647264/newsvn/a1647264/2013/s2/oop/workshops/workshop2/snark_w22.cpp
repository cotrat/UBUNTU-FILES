// rand: cstdlib; cin cout: iostream; string operators: string; list: vector
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(string guess,vector<string> trees)
{
  int x;
    bool check;
    for (x=0; x<3;x++)
      {
	if(guess==trees[x])
	  {
	    check = true;
	    break;
	  }
	else
	  {
	  check = false;
	  }
      }
    return(check);
}

int main()
{
	const int MAX_GUESSES = 3;
      
    // In C++ there are multiple ways to store variables in a list.
    // Throughout the semester we will talk about the different approaches.
    // In this example I've used a vector. In ugly snark I've used an array.
    vector<string> trees;
    trees.push_back("red");
    trees.push_back("yellow");
    trees.push_back("green");
    bool valid;

	int number_of_elements = trees.size(); 
	string guess;
	
	cout << "The Snark is hiding behind the red, yellow or green tree.\n";
	
	// Choose a location for the Snark
	srand(time(NULL));
	string tree_chosen = trees[rand() % number_of_elements];

	// Play...
	int guesses_taken = 0;
	bool hasGuessedSnark = false;

	while(hasGuessedSnark == false)
	{
	       
	  do
	    {
             cout<< "Please guess red yellow or green only"<<endl;
	     cin >> guess;
	     valid =  check(guess,trees);
	    }
	  while(valid==false);
		
		guesses_taken++;
		
		if (guess == tree_chosen)
		{
			cout << "You found the snark after " << guesses_taken << " guesses.\n";
            hasGuessedSnark = true;
		}
		else {
			cout << "Sorry, the Snark was not behind the " + guess + " tree.\n";
		}

		if (hasGuessedSnark == false && guesses_taken >= MAX_GUESSES)
		{
			cout << "You\'re a very poor Snark hunter!  The Snark was behind the " << tree_chosen << " tree.\n";	
            hasGuessedSnark = true;
		}
	}

	return 0;
}
