#include <iostream>
#include <algorithm>
#include <cstdlib>

// THIS CODE IS ADAPTED FROM THE LECTURE CODE
// INCLUDED IS THE ACTUAL IMPLEMENTATION OF THE SOLVE METHOD
// ALSO COMMENTS ADDED TO IMPROVE UNDERSATNDING

using namespace std;


class Classic_8Queen {

	public:
		Classic_8Queen() {
			for (int i = 0; i < 8; i++)
			{
				queens[i] = i; // For the i'th row the queen is in column i
			}
		}
		int solve();
		void disp();
	private:
		bool valid();
		int queens[8];
};

void Classic_8Queen::disp() 
{
	for (int i = 0; i < 8; i++)
	{
		cout << queens[i] << ' ';
			
	}
	cout << endl;
}

bool Classic_8Queen::valid()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 8; j++)
		{
			int diff_row = abs(i - j);
			int diff_col = abs(queens[i] - queens[j]);

			if(diff_col == diff_row)
				return false;

			/*if(queens[j]-j == queens[i]-i) // In the same top right to bootom left diag
			{
				return false;
			}

			if(queens[j]+j == queens[i]+i) // In the same top right to bootom left diag
			{
				return false;
			}*/
			

		}
		/*if(queens[i+1] == queens[i]+1) // Check on the top left-bottom right diagonal
			return false;
		if(queens[i+1] == queens[i]-1)
			return false;*/
		
	}

	return true;

}

int Classic_8Queen::solve()
{
	int count = 0;
	do {
		if(valid())
		{
			disp();
			count++;
		}
	} while (next_permutation(queens,queens+8));
	cout << endl << count;
}

int main()
{
	Classic_8Queen obj;
	obj.solve();
}





