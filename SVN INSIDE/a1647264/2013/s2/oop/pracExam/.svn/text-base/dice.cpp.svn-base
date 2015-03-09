#include<vector>
#include<iostream> 

using namespace std;

void checktest(bool result, bool expected)
{
	if(result==expected)
	{
		cout << "The Test Passed " << endl;
	}
	else
	{
		cout << "The Test Failed the result value was " << result << " But the expected value was " << expected;
	}
	cout << endl;
}

bool allValuesAreSame(vector<int> &dice)
{
	int idx,y;
	int current_element;
	for(idx =0; idx<dice.size(); idx++)
	{
		current_element = dice[idx];
		if((current_element < 1) or (current_element > 6)) // they must all be between 1 and 6
		{
			return(0);
		}

		for(y=0; y<dice.size(); y++)
		{
			if(dice[y]!=current_element) // they must all be equal
			{
				return(0);
			}
		}
	}
	return(1);
	
}

void test_all()
{
	int idx;
	vector<int> dice_1 (5); // all same between 1-7
	vector<int> dice_2 (5); // NOT BETWEEN 1-7 but all same
	vector<int> dice_3 (5); // different but between 1-7

	for(idx=0; idx<5; idx++)
	{
		dice_1[idx] = 2;
		dice_2[idx] = 17;
		dice_3[idx] = 3;
	}

	dice_3[2] = 4; // Making one element different
	
	bool result1, result2, result3;
	bool expected1, expected2, expected3;

	// Assigning the expected bools
	expected1 = 1;
	expected2 = 0;
	expected3 = 0;

	// calling the tests
	result1 = allValuesAreSame(dice_1);
	result2 = allValuesAreSame(dice_2);
	result3 = allValuesAreSame(dice_3);

	// checking the tests
	checktest(result1, expected1);
	checktest(result2, expected2);
	checktest(result3, expected3);

}


int main(int argc, char* argv[])
{
	int idx;
	for(idx=0; idx<argc; idx++)
	{
		string argstr = string(argv[idx]);
		if(argstr == "--test")
		{
			test_all();
		}
	}
	
	
}
