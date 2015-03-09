#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<string> scoreGuess(vector<string> guess, vector<string> ans, int leng_guess)
{

	int k = 0;
	int ans_it,i,guess_it; // Iterators
	vector<int> check_a(leng_guess);
	vector<int> check_g(leng_guess);
	vector<string> score(leng_guess);
	int b_count = 0;
	int w_count = 0;
	int empty;
	
	for( ans_it = 0; ans_it < leng_guess; ans_it++) // Iterating through the asnwers
	{
	
	  for(guess_it = 0; guess_it<leng_guess; guess_it++) //Iterating through the guesses
		{
		
		  if((ans_it==guess_it) && (guess[guess_it]==ans[ans_it])) // Checking for black pegs (colour and place)
			{
				b_count++;
				check_a[ans_it] = 1;
				check_g[ans_it] =1;
			}	
			
			else if((check_a[ans_it]!=1) && (check_g[guess_it]!=1) && (guess[guess_it]!=ans[guess_it]) && (guess[guess_it]==ans[ans_it]) && (guess[ans_it]!=ans[ans_it]))
			{
			  // Checking for white pegs, but as it is in the same loop must make sure that you are not giving a white peg before a black peg ( must check
			  // the peg above/below to ensure its not the same colour, also check that that spot in the check answer or check guess array hasnt been used)
				w_count++;
				check_a[ans_it] = 1;
				check_g[guess_it]=1;				
			}				
		}	
		
	}
	
	for( i = 0; i < leng_guess; i++) //Simply filling the score array
	{
		if(b_count>0)
			{
				score[i] = "Black";
				b_count--;
			}
		else if(w_count>0)
			{
				score[i] = "White";
				w_count--;
			}
		else
			{
				score[i] = " Empty";
			}
	
	}
	
	return(score);

	
}

int main()
{
	int leng_guess,i,rand_col;
	cout << "Inout the length of the code you desire"<<endl;
	cin >> leng_guess;
	vector<string> ans(leng_guess);
	vector<string> score(leng_guess);
	vector <string> guess(leng_guess);
	srand(time(NULL));
	for(i=0;i<leng_guess;i++)
	{
		cin >> ans[i];
		// rand_col = rand() % 4;
		// if (rand_col == 0)
		// {
			// ans[i] = "yellow";
		// }
		// else if (rand_col == 1)
		// {
			// ans[i] = "red";
		// }
		// else if (rand_col == 2)
		// {
			// ans[i] = "blue";
		// }
		// else if(rand_col == 3)
		// {
			// ans[i] = "green";
			
		// }
		// cout << ans[i] <<endl;
		
		do // Do while loop to ensure the user is inputting a valid guess
		{
			cout << "Type your guess , please choose only one of red, green, yellow or blue!";
			cin >> guess[i];
		}
		while((guess[i]!="red") && (guess[i]!="green") && (guess[i]!="yellow") && (guess[i]!="blue"));
		cout << "guess was " << guess[i] <<endl;
	}

	score = scoreGuess(guess,ans,leng_guess); // Calling the scoreguess function using the code, guess and the length
	
	for( i = 0; i < leng_guess; i++) // Displaying the secret code
	{
	  cout << ans[i]<<" ";
	}
	cout << " Was the secret code " <<endl;

	for( i = 0; i < leng_guess; i++) // Displaying the users guess code
	{
	  cout << guess[i]<<" ";
	}
	cout << " Was the users guess "<<endl;
	
	for( i = 0; i < leng_guess; i++) // Displaying the users score Black pegs listed first, then white, then empty
	{
	  cout << score[i]<<" ";
	}
	cout<< "Is the users score ";
	
}
