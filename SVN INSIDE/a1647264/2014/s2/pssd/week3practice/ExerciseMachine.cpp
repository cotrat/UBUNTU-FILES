#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdio.h>
#include <math.h>
#include <sstream>
using namespace std;


class ExerciseMachine
{
  public:
	int getPercentages(string time)
	{
		int hrs = atoi(time.substr(0,2).c_str());
		int mins = atoi(time.substr(3,2).c_str());
		int secs = atoi(time.substr(6,2).c_str());

		int seconds = hrs * (60*60) + mins*60 + secs; // total amount of seconds
		//cout << seconds;
		int i;
		int ctr = 0;
		for (i = 1; i < 100; i++)
		{
			int num = (seconds * i) / 100;
      			if (num * 100 == seconds * i)
			{
				ctr++;
			}
    
		}
		cout << ctr;
		
	}

 
};
 
int main()
{
      	ExerciseMachine a;
	a.getPercentages("00:30:00");
	       
}


