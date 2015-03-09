#include <iostream>
#include <cstdlib>
using namespace std;
 
 
class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {
	int amt_eat = 0;


	for(int j = 0; j <= branch; j+=rest)
	{
		if(j%leaf == 0)
		{
			amt_eat++;
		}

	}
    return amt_eat;  // return your result
  }
};

