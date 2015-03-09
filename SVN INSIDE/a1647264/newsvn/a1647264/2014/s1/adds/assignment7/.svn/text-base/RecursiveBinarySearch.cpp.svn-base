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
		return -1; // Boundary case, if lower is ever greater than upper we have nothing to search
	}
	
	int midpoint = (lower+upper)/2;

	if( toSearch.at(midpoint) > key )
	{	
		return bSearch(toSearch, key, lower, midpoint - 1); // Call binary search on the 'left' side of the vector
	}
	else if( toSearch.at(midpoint) < key )
	{
		return bSearch(toSearch, key, midpoint + 1, upper); // Call binary search on the 'righ' side of the vector
	}
	else
	{
		return midpoint;
	}
}
