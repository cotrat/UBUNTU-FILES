#include<iostream>

using namespace std;


bool isaMUString(char* sequence, int size)
{
	int x;
	int y=0;
	for(x = 0; x < size; x++)
		{
		if((sequence[x] == 'M') || (sequence[x] == 'U') || (sequence[x] == 'I'))
			{
			y++;
			}
		}
		
	if(y == size)
	{
		
		return(1);
	}
	
	return(0);
}

bool canApplyrule2(char* sequence, int size)
{
	int x = 0;
	if(sequence[0]=='M')
	{
		return(1);
	}
	else{
		return(0);
	}
}

bool canApplyrule1(char* sequence, int size)
{
	int x = 0;
	if(sequence[size-1]=='I')
	{
		return(1);
	}
	else{
		return(0);
	}
}

char *applyRule1(char* sequence, int size)
{
	
	
	int x;
	char* char_rule1;
	char_rule1 = new char[size+1];

	for(x=0; x<size; x++)
	{
		char_rule1[x] = sequence[x];
	}
	
	return(char_rule1);
	

}

/*char *applyRule2(char* sequence, int size)
{
	char* char_rule2;
	int new_size = size + (size-1);
	int x;
	char_rule2 = new char[new_size];

	for(x=0; x<size; x++)
	{
		char_rule2[x] = sequence[x];
	}
	
	for(x=size; x < new_size; x++)
	{
		char_rule2[x] = sequence[x-(size-1)];
	}
	
	return(char_rule2);

}
*/
void printing(char* sequence, int size)
{
	int x;
	for(x=0; x<size; x++)
	{
		cout << sequence[x];
	}
}

int main()
{
	char *char_seq;
	int n;
	int x;
	char_seq = new char[n];
	cout << "Enter the size of you array  ";
	cin >> n;
	for(x = 0; x < n; x++)
		{
		cout << "Enter the char value M U or I    ";
		cin >> char_seq[x];
		}
	bool check_MUstr = isaMUString(char_seq,n);
	bool check_rule1 = canApplyrule1(char_seq,n);
	bool check_rule2 = canApplyrule2(char_seq,n);

	// Printing out whether it is a valid MU string or not

	if(check_MUstr==1)
	{
		cout << "That was a valid MU String :)" << endl;
	}
	else
	{
		cout << "That was not a valid MU String :(" << endl;
		return(0);
	}

	//Printing whether rule 1, 2 or both can be applied

	if((check_rule1==1) && (check_rule2==1))
	{
		cout << "Rule 1 and 2 can be applied!" << endl;
		
	}
	else if(check_rule1==1)
	{
		cout << "Rule one can be applied!" << endl;
	}
	else if(check_rule2==1)
	{
		cout << "Rule two can be applied!" << endl;
	}
	else
	{
		cout << "No rules can be applied " << endl;
		delete char_seq;
	}

	
	char* pointer_char_rule1 = applyRule1(char_seq,n);
	printing(pointer_char_rule1,n+1);



}
