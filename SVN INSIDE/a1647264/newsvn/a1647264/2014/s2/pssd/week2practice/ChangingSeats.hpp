#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;


class ChangingString
{
  public:
  void distance(string A, string B, int K)
  {
	vector<int> distances;
	for(int i = 0; i < A.length(); i++)
	{
		distances.push_back(abs(A[i]-B[i]));
	}

	
	for(int j = 0; j < K; j++)
	{
		int max = 0;
		int max_loc;
		for ( int l = 0; l < distances.size(); l++)
		{
			if (distances[l] > max)
			{
				max = distances[l];
				max_loc = l;
			}
			
		}
		
		A[max_loc] = B[max_loc];
		distances[max_loc] = 0;
	}

	int sum = 0;
	for (int x = 0; x < A.length(); x++)
	{
		sum = sum + abs(A[x]-B[x]);
	}
	return sum;
  }
};


