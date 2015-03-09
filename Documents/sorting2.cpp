#include <vector>
#include "math.h"
#include <iostream>

using namespace std;

int main()
{
	vector<int> toSort;
	toSort.push_back(123);
	toSort.push_back(1132);
	toSort.push_back(53);
	toSort.push_back(1);
	toSort.push_back(1124);
	toSort.push_back(12456);

	// Insertion Sort

	int holepos;
	int x;
	int value;
	
	for(x = 1; x < 6; x++)
	{
		holepos = x;
		value = toSort.at(x);
		while((holepos > 0 ) and (value < toSort.at(holepos - 1)))
		{
			toSort.at(holepos) = toSort.at(holepos - 1);
			holepos = holepos - 1;
		}
		toSort.at(holepos) = value;
	}

	for(int x=0;x<6;x++)
	{
		cout << toSort.at(x) << "  ";
	}

	// Binary Search

	int min;
	int max;
	int mid;
	int value2;
	min = 0;
	max = 5;
	value2 = 1124;
	
	while(max >= min)
	{
		mid = floor((min+max)/2);

		if(value2 < toSort.at(mid))
		{
			max = mid - 1;
		}
		else if(value2 > toSort.at(mid))
		{
			min = mid + 1;
		}
		else
		{
			cout << "The value is at index " << mid << endl;;
			break;
		}
	}

	// Selection Sort
	
	

	vector<int> toSort2;
	toSort2.push_back(123);
	toSort2.push_back(1132);
	toSort2.push_back(53);
	toSort2.push_back(1);
	toSort2.push_back(1124);
	toSort2.push_back(12456);
	int i;
	int j;
	int temp;
	for(i = 0; i < 5; i++)
	{
		min = i;
		for( j = i + 1; j < 6; j ++)
		{
			if(toSort2.at(j) < toSort2.at(min))
			{
				min = j;
			}
		}

		if(min!=i)
		{
			temp = toSort2.at(i);
			toSort2.at(i) = toSort2.at(min);
			toSort2.at(min) = temp;
		}

	}


	for(int x=0;x<6;x++)
	{
		cout << toSort2.at(x) << "  ";
	}














}
