#include <vector>
#include "QuickSort.h"

using namespace std;

QuickSort::QuickSort()
{

}

void QuickSort::qSort(vector<int> &toSort, int lower, int upper)
{
	if (lower < upper)
	{
		int pivot_index = (lower + upper) / 2;
		int new_pivot = Split(toSort, lower, upper, pivot_index);
		qSort(toSort, lower, new_pivot - 1);
		qSort(toSort, new_pivot + 1, upper);	
	}
}

// This function is used to "sort" the vecotr in-place

int QuickSort::Split(vector<int> &toSort, int lower, int upper, int pivot_index)
{
	int new_pivot = lower;
	int pivot_value = toSort.at(pivot_index);

	swap(toSort.at(pivot_index), toSort.at(upper)); // Storing the pivot point at the end of the vector

	for (int i = lower; i <= upper - 1; i++)
	{
		if (toSort.at(i) <= pivot_value)
		{
			swap(toSort.at(i), toSort.at(new_pivot));
			new_pivot++;
		}
	}
	
	swap(toSort.at(new_pivot), toSort.at(upper)); // Placing the pivot point back

	return new_pivot;
}
