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
				score[i] = "Empty";
			}
	
	}
	
	return(score);

	
}

int printingT(vector<string> guess, vector<string> ans, vector<string> score, vector<string> expected, int leng_guess)
{
	int i;
	int ctr =0;
	
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
		if(score[i]==expected[i])
		{
			ctr++;
		}
	}

	cout<< "Is the users score "<<endl;

	if(ctr==4)
	{
		cout << "IT WORKED!"<<endl;
	}
	return(0);
}


void runUnitTests()
{
	
	vector<string> guess(4), ans(4),expected(4), guess2(4), ans2(4), expected2(4), guess3(4), ans3(4), expected3(4), score(4);

	string guessAr[] = {"Blue","TheColourBlue","Red","Red"};
	string ansAr[] = {"Red","Blue","Red","Blue"};
	string expectedAr[] = {"Black", "White", "White", "Empty"};
	guess.assign(guessAr,guessAr+4);
	ans.assign(ansAr,ansAr+4);
	expected.assign(expectedAr,expectedAr+4);

	string guess2Ar[] = {"Red","Red","Red","Red"};
	string ans2Ar[] = {"Red","Blue","Blue","Red"};
	string expected2Ar[] = {"Black", "Black", "Empty", "Empty"};
	guess2.assign(guess2Ar,guess2Ar+4);
	ans2.assign(ans2Ar,ans2Ar+4);
	expected2.assign(expected2Ar,expected2Ar+4);

	string guess3Ar[] = {"Red","Blue","Yellow","Green"};
	string ans3Ar[] = {"Yellow","Blue","Red","Red"};
	string expected3Ar[] = {"Black", "White", "White", "Empty"};
	guess3.assign(guess3Ar,guess3Ar+4);
	ans3.assign(ans3Ar,ans3Ar+4);
	expected3.assign(expected3Ar,expected3Ar+4);
	

	score = scoreGuess(guess,ans,4); // Calling the scoreguess function using the code, guess and the length
	printingT(guess,ans,score,expected,4);

	score = scoreGuess(guess2,ans2,4); // Calling the scoreguess function using the code, guess and the length
	printingT(guess2,ans2,score,expected2,4);

	score = scoreGuess(guess3,ans3,4); // Calling the scoreguess function using the code, guess and the length
	printingT(guess3,ans3,score,expected3,4);
	
}



int printing(vector<string> guess, vector<string> ans, vector<string> score, int leng_guess)
{
	int i;
	
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
	return(0);
}

void runInputTests()
{
	int leng_guess,i,rand_col;
	//cout << "Input the length of the code you desire"<<endl;
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
	}	
	for(i=0;i<leng_guess;i++){	
		//do // Do while loop to ensure the user is inputting a valid guess
		//{
			//cout << "Type your guess , please choose only one of red, green, yellow or blue!";
			cin >> guess[i];
		//}
		//while((guess[i]!="red") && (guess[i]!="green") && (guess[i]!="yellow") && (guess[i]!="blue"));
		//cout << "guess was " << guess[i] <<endl;
	}

	for(i=0;i<leng_guess;i++){
		if((guess[i]!="red") && (guess[i]!="green") && (guess[i]!="yellow") && (guess[i]!="blue"))
		{
			cout << "That was not a valid guess";
			exit(EXIT_FAILURE);
		} 

	}
	score = scoreGuess(guess,ans,leng_guess); // Calling the scoreguess function using the code, guess and the length
	printing(guess,ans,score,leng_guess);

}


int main(int argc, const char *argv[]) {
    for(unsigned int arg = 0; arg < argc; arg++) {
        string argStr = string(argv[arg]);
		if (argStr == "-test")
		{
			runUnitTests();
			break;
		}
		if (argStr == "-inputTest")
		{
			runInputTests();
			break;
		}
        
    }
    
	
}
