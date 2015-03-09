#include <iostream>
#include <vector>
using namespace std;
 
 
class ThrowTheBall
{
  public:
  int timesThrown(int N, int M, int L)
  {
	vector<int> player_amounts;
	player_amounts.assign(N+1,0);
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
					//cout << carrier << " Threw the ball to";
					carrier = (carrier - L ) + (N);
					//cout << "   " << carrier << endl;
					player_amounts[carrier]++;
					passed++;
				}
				else
				{
					//cout << carrier << " Threw the ball to";
					carrier = carrier - L;
					//cout << "   " << carrier << endl;
					player_amounts[carrier]++;
					passed++;
				}
			}
			else
			{
				if((carrier + L ) > N) // Even moves left which is add
				{
					//cout << carrier << " Threw the ball to";
					carrier = (carrier + L) - (N);
					//cout << "   " << carrier << endl;
					player_amounts[carrier]++;
					passed++;
				}
				else
				{
					//cout << carrier << " Threw the ball to";
					carrier = carrier + L;
					//cout << "   " << carrier << endl;
					player_amounts[carrier]++;
					passed++;
				}
			}
		}
	}
	return passed;
  }
};

/*int main()
{
	ThrowTheBall a;
	cout << a.timesThrown(5,3,2);
}*/




