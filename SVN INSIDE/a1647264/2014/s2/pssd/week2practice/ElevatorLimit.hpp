#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;


class ElevatorLimit
{
  public:
  vector<int> getRange(vector<int> enter, vector<int> exit, int physicalLimit)
  {
	vector<int> minmax;
	int occupancy = 0;
	int min_occ = 0;
	int max_occ = 0;
	for (int i = 0; i < exit.size(); i++)
	{
		occupancy = occupancy - exit.at(i);
		if (occupancy < min_occ)
		{
			min_occ = occupancy;
		}
		occupancy = occupancy + enter.at(i);
		if (occupancy > max_occ)
		{
			max_occ = occupancy;
		}
	}

	if ((max_occ <= physicalLimit) and (max_occ - min_occ <= physicalLimit))
	{
		minmax.push_back(0-min_occ);
		minmax.push_back(physicalLimit-max_occ);
	}
	
	return minmax;
  }
};
