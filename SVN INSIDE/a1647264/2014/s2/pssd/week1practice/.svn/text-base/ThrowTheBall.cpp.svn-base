#include <iostream>
using namespace std;
 
 
class ThrowTheBall
{
  public:
  int timesThrown(int N, int M, int L)
  {
	int player_amounts[N+1];
	int passed = 0;
	player_amounts[1] = 1;
	int carrier = 1;

	while(1)
	{
		if(player_amounts[carrier] == M)
		{
			return passed;
		}
		else
		{
			if((player_amounts[carrier] % 2) == 1) // ODD MOVES RIGHT, WHICH IS SUBTRACT
			{
				if((carrier - L) < 1)
				{
					carrier = (carrier - L ) + N;
					player_amounts[carrier]++;
					passed++;
				}
				else
				{
					carrier = carrier - L;
					player_amounts[carrier]++;
					passed++;
				}
			}
			else
			{
				if((carrier + L ) > N) // Even moves left which is add
				{
					carrier = (carrier + L) - N;
					player_amounts[carrier]++;
					passed++;
				}
				else
				{
					carrier = carrier + L;
					player_amounts[carrier]++;
					passed++;
				}
			}
		}
	}
	return passed;
  }
};

int main()
{
	ThrowTheBall a;
	cout << a.timesThrown(5,3,2);
}

