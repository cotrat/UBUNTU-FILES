#include <vector>
#include "RecursiveBinarySearch.h"

using namespace std;

RecursiveBinarySearch::RecursiveBinarySearch()
{

}

int RecursiveBinarySearch::bSearch(vector<int> &toSearch, int key, int lower, int upper)
{
	if( lower > upper )
	{
		return -1;
	}
	
	int midpoint = (lower+upper)/2;

	if( toSearch.at(midpoint) > key )
	{	
		return bSearch(toSearch, key, lower, midpoint - 1);
	}
	else if( toSearch.at(midpoint) < key )
	{
		return bSearch(toSearch, key, midpoint + 1, upper);
	}
	else
	{
		return midpoint;
	}
}
