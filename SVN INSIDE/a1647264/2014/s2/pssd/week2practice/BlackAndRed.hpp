#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;


class BlackAndRed
{
  public:
  int cut(string input)
  {
	int b_count = 0;
	int r_count = 0;
	bool good = 1;
	string before;
	string after;
	string total;
	for(int i = 0; i < input.length(); i++)
	{
		before = input.substr(0,i);
		after = input.substr(i);
		total = after+before;
		for(int j = 0; j < total.length(); j++)
		{
			if(total[j] == 'B')
			{
				b_count++;
			}
			else
			{
				r_count++;
			}

			if(r_count > b_count)
			{
				good = 0;
				break;
			}
		}

		if(good)
		{
			return i;
		}
		good = 1;
		b_count = 0;
		r_count = 0;
		//cout << " STUFF BEFORE " << before << " STUFF AFTER " << after << endl;
	}
  }
};

/*int main()
{
	BlackAndRed a;
	a.cut("RBRBBRRRRBBBRBBRRBRBBRRRBRBBBRBRBRBRBRRB");
}*/
